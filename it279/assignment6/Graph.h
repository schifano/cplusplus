#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <map>
#include <set>

#include "PriorityQueue.h"
#include "GPSLocation.h"
#include <utility> // std::pair
#include <limits> // std::numeric_limits - infinity()

using namespace std;

class Graph
{
	// Create a list class to store information
	class ListInfo {
		friend class Graph;
		public:
			ListInfo() {
				traversed = false;
				last_vertex = -1;
				lShort = numeric_limits<float>::infinity();	
			}
			~ListInfo() {
			}
		private:
			bool traversed;
			int last_vertex;
			float lShort;
	};

 public:
  Graph();
  ~Graph();
  inline int getNumVertices()
  {
      return vertex_map.size();
  }

  inline int getNumEdges()
  {
      return edge_count;
  }

  vector<GPSLocation> shortest(const GPSLocation& start,const GPSLocation& end);

  // functions
  void addVertex(int id,const GPSLocation& loc);
  void addEdge(int v1,int v2,float weight);

 private:
	map<int, GPSLocation>::iterator it; // vertex iterator
	map<int, float>::iterator it_edge; // edge iterator
 	map<int, GPSLocation> vertex_map;
	map<int, map<int, float> > edge_map;
	vector<ListInfo> vertex_info;
	PriorityQueue<int> q;
	float infinity;
	int edge_count;
	
	// helper function
	void dijkstra(int s, int t);
};

#endif
