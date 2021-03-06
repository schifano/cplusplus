#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Graph.h"
#include "GPSLocation.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include <glm/gtc/type_ptr.hpp>


Graph graph;
int WINDOW_WIDTH,WINDOW_HEIGHT;
GLuint worldMapTexture;
string filename; //filename of the graph information
float maxlong,minlong,maxlat,minlat;
float radiusEarth = 7000;


glm::mat4 modelView,invModelView,trackballTransform;
int mousex,mousey;
bool trackballOn;


void init();
void idle();
unsigned int loadTexture(const string& filename);
unsigned int makeCheckImage(void);
void initGraph(string& filename);
void resize(int width,int height);
void display();
void drawQuad();
void drawSphere(int STACKS,int SLICES);
void mouse(int button,int state,int x,int y);
void mousemove(int x,int y);
void keyboard(unsigned char ch,int x,int y);

GPSLocation from,to;
bool first_location;
bool drawGlobe;
float angle;

vector<GPSLocation> path;


int main(int argc,char *argv[])
{

	if (argc!=2)
	{
        cout << "Using default name" << endl;
        filename = "worldgraph.txt";
	}
    else
        filename = argv[1];
	
	glutInit(&argc,argv);
	
	//we want a glut window that is double-buffered and supports red, green, blue and alpha (transparency)
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);

    //the initial size of the window
    glutInitWindowSize(500,500);

    //the position of the top left corner of the window on the screen
    glutInitWindowPosition(100,100);


    //this call finally creates and shows the window with the provided title.
    //Important: No OpenGL command before this line will work!.
    glutCreateWindow("Flight Path");
 
 	init();
 	
 	glutDisplayFunc(display);
    glutReshapeFunc(resize);
 	glutMouseFunc(mouse);
 	glutMotionFunc(mousemove);
    glutKeyboardFunc(keyboard);




 	
 	glutMainLoop();
 	
 	return 0;
 

}



void display()
{
    float x,y,z;

    glEnable (GL_LINE_SMOOTH);
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint (GL_LINE_SMOOTH_HINT, GL_DONT_CARE);


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_DECAL);

    modelView = glm::mat4(1.0);
    glColor3f(1,0,0);
    glMatrixMode(GL_TEXTURE);
    glLoadIdentity();
 

    modelView = modelView * glm::lookAt(glm::vec3(0,0,8000),glm::vec3(0,0,0),glm::vec3(0,1,0));
 
    if (drawGlobe)
        modelView = modelView * glm::scale(glm::mat4(1.0),glm::vec3(radiusEarth,radiusEarth,radiusEarth));
    else
        modelView = modelView * glm::scale(glm::mat4(1.0),glm::vec3(WINDOW_WIDTH,WINDOW_HEIGHT,1));

    if (drawGlobe)
        modelView = modelView * trackballTransform;


    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(glm::value_ptr(modelView));
    if (drawGlobe)
        drawSphere(50,50);
    else
        drawQuad();
    glDisable(GL_TEXTURE_2D);


    glColor3f(0,1,0); // line is now lime green. it's my favorite color ^_^ hope that's s'okay
    glLineWidth(5);


	  if (drawGlobe)
    {
    	
        glBegin(GL_LINE_STRIP);
        for (int i=0;i<path.size();i++)
        {
            x = 1.01*cos(path[i].getLatitude()*3.14159/180) * cos(path[i].getLongitude()*3.14159/180);
            y =  1.01*sin(path[i].getLatitude()*3.14159/180);
            z = - 1.01*cos(path[i].getLatitude()*3.14159/180) * sin(path[i].getLongitude()*3.14159/180);
            glVertex3f(x,y,z);
        }
        glEnd();
      
    }
    else
    {
        glBegin(GL_LINE_STRIP);
        for (int i=0;i<path.size();i++)
        {
            if (path[i].getLongitude()<0)
                x = 0.5*(1 + (path[i].getLongitude()+180)/180);
            else
                x = 0.5 * path[i].getLongitude()/180;
            y = (path[i].getLatitude()+90)/180;
            z = 1;
            glVertex3f(x,y,z);
            
        }
        glEnd();
        
    }

    invModelView = glm::inverse(modelView);
		

    glutSwapBuffers();
    
   
}






void drawSphere(int STACKS,int SLICES)
{
    int i,j;
    float phi,theta,nextphi,nexttheta;
    float PI = 3.14159f;

    glBindTexture(GL_TEXTURE_2D,worldMapTexture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); //if the s-coordinate goes outside (0,1), repeat it
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); //if the t-coordinate goes outside (0,1), repeat it

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);  //for texture coordinates that are not integer locations, do (bi)linear interpolation
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);  //for texture coordinates that are not integer locations, do (bi)linear interpolation

    glBegin(GL_QUADS);
    for (i=0;i<STACKS;i++)
    {
        phi = -PI/2 + i*PI/STACKS;
        nextphi = -PI/2 + (i+1)*PI/STACKS;
        for (j=0;j<SLICES;j++)
        {
            theta = j*2*PI/SLICES;
            nexttheta = (j+1)*2*PI/SLICES;

            glNormal3f(cos(phi)*cos(theta),sin(phi),-cos(phi)*sin(theta));
            glTexCoord2f((float)j/SLICES,(float)i/(STACKS+1));
            glVertex3f(cos(phi)*cos(theta),sin(phi),-cos(phi)*sin(theta));

            glNormal3f(cos(phi)*cos(nexttheta),sin(phi),-cos(phi)*sin(nexttheta));
            glTexCoord2f((float)(j+1)/SLICES,(float)i/(STACKS+1));
            glVertex3f(cos(phi)*cos(nexttheta),sin(phi),-cos(phi)*sin(nexttheta));

            glNormal3f(cos(nextphi)*cos(nexttheta),sin(nextphi),-cos(nextphi)*sin(nexttheta));
            glTexCoord2f((float)(j+1)/SLICES,(float)(i+1)/(STACKS+1));
            glVertex3f(cos(nextphi)*cos(nexttheta),sin(nextphi),-cos(nextphi)*sin(nexttheta));

            glNormal3f(cos(nextphi)*cos(theta),sin(nextphi),-cos(nextphi)*sin(theta));
            glTexCoord2f((float)j/SLICES,(float)(i+1)/(STACKS+1));
            glVertex3f(cos(nextphi)*cos(theta),sin(nextphi),-cos(nextphi)*sin(theta));


        }
    }
    glEnd();
}


void drawQuad()
{

    glBindTexture(GL_TEXTURE_2D,worldMapTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); //if the s-coordinate goes outside (0,1), repeat it
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); //if the t-coordinate goes outside (0,1), repeat it

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);  //for texture coordinates that are not integer locations, do (bi)linear interpolation
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);  //for texture coordinates that are not integer locations, do (bi)linear interpolation



    glBegin(GL_QUADS);

    glTexCoord2f(0,0);
    glVertex2f(0,0);

    glTexCoord2f(1.0f,0);
    glVertex2f(1,0);

    glTexCoord2f(1.0f,1.0f);
    glVertex2f(1,1);

    glTexCoord2f(0,1.0f);
    glVertex2f(0,1);

    glEnd();


}

void mouse(int button,int state,int x,int y)
{
    glm::vec4 point;

    if (button == GLUT_RIGHT_BUTTON)
    {
        if (state == GLUT_UP)
        {
            if (drawGlobe)
            {
                glm::vec4 start,dir;

                start = glm::vec4(x*16000.0f/WINDOW_WIDTH - 8000 ,(WINDOW_HEIGHT - y)*16000.0f/WINDOW_WIDTH - 8000.0f * WINDOW_HEIGHT/WINDOW_WIDTH,0,1);
                dir = glm::vec4(0,0,-1,0);

                //transform start and dir by inverse of modelview

                start = invModelView * start;
                dir = invModelView * dir;

                //find intersections

                float A = glm::length(dir) * glm::length(dir);
                float B = 2*(glm::dot(start,dir));
                float C = start.x*start.x + start.y*start.y + start.z*start.z - 1;

                float disc = B*B - 4*A*C;

                cout << "disc = " << disc << endl;

                if (disc<0)
                    return;

                float t = (-B + sqrt(disc))/(2*A);

                float t1 = (-B - sqrt(disc))/(2*A);

                if (t1<t)
                    t = t1;

                point = start + dir*t;

            }
            if (first_location)
            {
                //first location
               //
                if (drawGlobe)
                {
                    from.setLongitude(180*atan2(-point.z,point.x)/3.14159);
                    from.setLatitude(180*asin(point.y)/3.14159);
                }
                else
                {
                    if (x>0.5*WINDOW_WIDTH)
                        from.setLongitude((x-0.5*WINDOW_WIDTH)*180/(0.5*WINDOW_WIDTH)-180);
                    else
                        from.setLongitude(x*180/(0.5*WINDOW_WIDTH));

                    from.setLatitude((WINDOW_HEIGHT - y)*180/WINDOW_HEIGHT - 90);
                }
 
            }
            else
            {
                //second location
               //
                if (drawGlobe)
                {
                    to.setLongitude(180*atan2(-point.z,point.x)/3.14159);
                    to.setLatitude(180*asin(point.y)/3.14159);
                }
                else
                {
                    if (x>0.5*WINDOW_WIDTH)
                        to.setLongitude((x-0.5*WINDOW_WIDTH)*180/(0.5*WINDOW_WIDTH)-180);
                    else
                        to.setLongitude(x*180/(0.5*WINDOW_WIDTH));

                    to.setLatitude((WINDOW_HEIGHT - y)*180/WINDOW_HEIGHT - 90);
                }
             //get path
                path = graph.shortest(from,to);


               //refresh
                glutPostRedisplay();
           }
            first_location = !first_location;
        }

    }
    else if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            mousex = x;
            mousey = WINDOW_HEIGHT - y;
            trackballOn = true;
        }
        else if (state == GLUT_UP)
        {
            trackballOn = false;
        }
    }
}

void mousemove(int x,int y)
{
    float diffx,diffy;

    if (trackballOn)
    {
        diffx = x-mousex;
        diffy = WINDOW_HEIGHT - y - mousey;

        mousex = x;
        mousey = WINDOW_HEIGHT - y;


        glm::vec3 axis(-diffy,diffx,0);

        float angle = (180.0f/3.14159) * (diffx*diffx + diffy*diffy)/radiusEarth;
        glm::normalize(axis);

        trackballTransform = glm::rotate(glm::mat4(1.0),angle,axis) * trackballTransform;
        glutPostRedisplay();
    }
}

void resize(int width, int height)
{
    WINDOW_WIDTH = width;
    WINDOW_HEIGHT = height;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(120,(float)WINDOW_WIDTH/WINDOW_HEIGHT,0.1f,100000.0f);
    glOrtho(-8000,8000,-8000.0f*WINDOW_HEIGHT/WINDOW_WIDTH,8000.0f*WINDOW_HEIGHT/WINDOW_WIDTH,0.1,100000);
    glViewport(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);
}

void init()
{
    initGraph(filename);
    worldMapTexture = loadTexture("earthmap.ppm");
    glClearColor(1,1,1,1);

    trackballTransform = glm::mat4(1.0);


    trackballOn = false;
    drawGlobe = false;
    first_location = true;
    angle = 0;
}

void keyboard(unsigned char ch, int x, int y)
{
    switch (ch)
    {
    case 'R':
    case 'r':
        trackballTransform = glm::mat4(1.0);
        glutPostRedisplay();
        break;
    case 'g':
    case 'G':
        drawGlobe = true;
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        //gluOrtho2D(0,WINDOW_WIDTH,0,WINDOW_HEIGHT);
        //gluPerspective(120,(float)WINDOW_WIDTH/WINDOW_HEIGHT,0.1f,100000.0f);
        glOrtho(-8000,8000,-8000.0f*WINDOW_HEIGHT/WINDOW_WIDTH,8000.0f*WINDOW_HEIGHT/WINDOW_WIDTH,0.1,100000);
        glutPostRedisplay();
        break;
    case 'm':
    case 'M':
        drawGlobe = false;
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        //gluOrtho2D(0,WINDOW_WIDTH,0,WINDOW_HEIGHT);
        //gluPerspective(120,(float)WINDOW_WIDTH/WINDOW_HEIGHT,0.1f,100000.0f);
        glOrtho(0,WINDOW_WIDTH,0,WINDOW_HEIGHT,0.1,100000);
        glutPostRedisplay();
        break;
    }
}

void initGraph(string& filename)
{
  	int numVertices,numEdges;
    float latitude,longitude;
    GPSLocation loc;
    int v1,v2;
    float weight;

  	ifstream in(filename.c_str());

  	if (!in.is_open())
    	return;

 	//read in the number of vertices
  	in >> numVertices;

  	//read them in
  	for (int i=0;i<numVertices;i++)
  	{
    	in >> latitude >> longitude;
    	loc.setLatitude(latitude);
    	loc.setLongitude(longitude);
    	graph.addVertex(i,loc);

        if (i==0)
        {
            minlat = maxlat = latitude;
            minlong = maxlong = longitude;
        }
        else
        {
            if (longitude>maxlong)
                maxlong = longitude;

            if (longitude<minlong)
                minlong = longitude;

            if (latitude>maxlat)
                maxlat = latitude;

            if (latitude<minlat)
                minlat = latitude;
        }
  	}

  	//read in the number of edges
  	in >> numEdges;
  
  	//read them in
  	for (int i=0;i<numEdges;i++)
  	{
    	in >> v1 >> v2 >> weight;
    	graph.addEdge(v1,v2,weight);
  	}
  	in.close();

    cout << "Read a graph with " << graph.getNumVertices() << " vertices and " << graph.getNumEdges() << " edges. " << endl;
}

unsigned int loadTexture(const string& filename)
{
    //this function reads in a .ppm file. Then it scales it so that each dimension is a power of 2. Finally
    //it creates a mip-mapped texture out of it, and returns the texture ID
    ifstream fp;
    GLubyte *bitmap;
    GLuint texid;
    string str;
    int i,j;
    int r,g,b;
    int factor;
    int width,height;

    fp.open(filename.c_str());
    //fp = fopen(filename.c_str(),"r");
    //if (!fp)
    //	return -1;

    if (!fp.is_open())
        return -1;

    //read in the word P3

    //fscanf(fp,"%s",string);
    fp >> str;


    //now read in the width and height

    //fscanf(fp,"%d %d",&width,&height);
    fp >> width >> height;

    //read in the factor
    //fscanf(fp,"%d",&factor);
    fp >> factor;

    bitmap = new GLubyte[3*width*height];

    for (i=0;i<height;i++)
    {
        for (j=0;j<width;j++)
        {
            //fscanf(fp,"%d %d %d",&r,&g,&b);
            fp >> r >> g >> b;
            bitmap[3*((height-1-i)*width+j)] = r;
            bitmap[3*((height-1-i)*width+j)+1] = g;
            bitmap[3*((height-1-i)*width+j)+2] = b;
        }
    }
    //fclose(fp);
    fp.close();




  //  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

//now convert to a texture
    glGenTextures(1,&texid);

    glBindTexture(GL_TEXTURE_2D,texid);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,(GLvoid *)bitmap);


    glBindTexture(GL_TEXTURE_2D,0);

    delete []bitmap;
    return texid;
}
  


unsigned int makeCheckImage(void)
{
    int checkImageWidth,checkImageHeight;

    checkImageWidth = 512;
    checkImageHeight = 256;
    GLfloat *checkImage = new GLfloat[3*checkImageWidth*checkImageHeight];
    int level,i, j, k,l,c,dim;
    unsigned int checkImageId;
    float r,g,b,a;
    int z;

    level = 0;

    z = 0x0020;
    for (i = 0; i < checkImageHeight; i++)
    {
        for (j = 0; j < checkImageWidth; j++)
        {
            c = (((i&z)==0)^((j&z)==0))*255;
            checkImage[3*(checkImageWidth*i +j)] = (GLfloat)(0+c)/255;
            checkImage[3*(checkImageWidth*i +j)+1] = (GLfloat)(0+c)/255;
            checkImage[3*(checkImageWidth*i +j)+2] = (GLfloat)(0+c)/255;
//			checkImage[i][j][3] = (GLubyte) 128;
        }
    }

     glGenTextures(1, &checkImageId);  //ask for a unique texture ID
    glBindTexture(GL_TEXTURE_2D,checkImageId);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, checkImageWidth,checkImageHeight, 0, GL_RGB, GL_FLOAT,checkImage);

    delete []checkImage;
    return checkImageId;

}
