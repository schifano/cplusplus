/*
	Rachel A Schifano
	IT 279
	Assignment 6
*/
#include "Graph.h"
#include "PriorityQueue.h"
#include <iostream>
#include <vector>
#include <algorithm> // std::reverse
using namespace std;

Graph::Graph()
{
	edge_count = 0;
	infinity = numeric_limits<float>::infinity();
}

Graph::~Graph()
{
}

void Graph::addVertex(int id,const GPSLocation& loc)
{
	// vertices start at 0 and are contiguous
	vertex_map[id] = loc;
}

void Graph::addEdge(int v1,int v2,float weight)
{
	edge_map[v1].insert(make_pair(v2, weight));
	edge_count++;
}

vector<GPSLocation> Graph::shortest(const GPSLocation& start,const GPSLocation& end)
{
	vector<GPSLocation> shortest_path; // store shortest path
	GPSLocation start_vertex, end_vertex; // store temp start & end locations closest to given points

	int start_ID, end_ID, temp_ID;
	float start_weight, end_weight, t_start_weight, t_end_weight;
	start_weight = infinity;
	end_weight = infinity;

	ListInfo *v_info;

	// Iterate through all vertices, determine which vertices are closest to the given GPS locations
	// Similar to simple finding max / min values like in IT 168
	for (it = vertex_map.begin(); it != vertex_map.end(); it++) {
		t_start_weight = start.getDistance(it->second);
		t_end_weight = end.getDistance(it->second);

		if (t_start_weight < start_weight) {
			start_weight = t_start_weight;
			start_ID = it->first;
		}

		if (t_end_weight < end_weight) {
			end_weight = t_end_weight;
			end_ID = it->first;
		}
		q.insert(it->first,infinity);
		v_info = new ListInfo();
		vertex_info.push_back(*v_info);	
	}
	
	// Dijkstra's Algorithm
	dijkstra(start_ID, end_ID);
	
	temp_ID = end_ID;
	shortest_path.push_back(end); // store end ID
	
	while (temp_ID != -1) {
		shortest_path.push_back(vertex_map[temp_ID]);
		temp_ID = vertex_info[temp_ID].last_vertex;
	}
	
	shortest_path.push_back(vertex_map[start_ID]);
	shortest_path.push_back(start);
	reverse(shortest_path.begin(), shortest_path.end());

	return shortest_path;  
}

// Dijkstra's Algorithm as a private helper function
void Graph::dijkstra(int s, int t)
{
	int id;
	ListInfo v;
	bool done = false;

	q.changePriority(s, 0);
	vertex_info[s].lShort = 0;

	while(!done)
	{
	  if(q.isEmpty())
	  {
	    done = true;
	  }
	  else
	  {
	    id = q.pop();
	    v = vertex_info[id];
	   
   	    if(v.lShort == infinity)
	    {
	      done = true;
 	    }
	    else
	    {
	      v.traversed = true;
	
	      if(id == t)
	      {
		done = true;
 	      }
	      else
	      {   
	        for (it_edge = edge_map[id].begin(); it_edge != edge_map[id].end(); it_edge++)
		{
		  if(vertex_info[it_edge->first].traversed != true)
		  {
		    if((vertex_info[id].lShort + edge_map[id][it_edge->first]) < vertex_info[it_edge->first].lShort)
		    {
		        q.changePriority(it_edge->first, edge_map[id][it_edge->first] + vertex_info[id].lShort);
			vertex_info[it_edge->first].lShort = vertex_info[id].lShort + edge_map[id][it_edge->first];
			vertex_info[it_edge->first].last_vertex = id;
		    } //end if
		  } //end if
		} //end for
	      } //end else
	    } // end else
	  } // end else
	} // end while
} // end function
