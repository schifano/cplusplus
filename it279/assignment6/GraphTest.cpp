#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#include "Graph.h"
#include "GPSLocation.h"

void initGraph(string filename);

Graph graph;

int main(int argc,char *argv[])
{
  if (argc!=2)
  {
    cout << "Usage is program-name graph-file" << endl;
  }

  initGraph(string(argv[1]));

  GPSLocation from,to;

  from.setLongitude(50);
  from.setLatitude(0);

  to.setLongitude(50);
  to.setLatitude(90);

  vector<GPSLocation> path;

  path =  graph.shortest(from,to);

  cout << "Path has " << path.size() << " vertices." << endl;
  for (int i=0;i<path.size();i++)
  {
    cout << "(" << path[i].getLatitude() << "," << path[i].getLongitude() << ")" << endl;
  }

  return 0;
}

void initGraph(string filename)
{
  int numVertices,numEdges;
  float latitude,longitude;
  float maxlong,minlong,maxlat,minlat;
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
