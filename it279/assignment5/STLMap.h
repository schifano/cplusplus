/*
	Rachel A Schifano
	IT 279 Assignment 5
*/

#ifndef _STLMAP_H_
#define _STLMAP_H_

#include "MapInterface.h"
#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

template<class S,class T>
class STLMap: public MapInterface<S,T>
{
 public:
  STLMap()
  {
  }

  ~STLMap()
  {
  }

  // Given a key, find whether there is a (key, value) pair in the map that has the same key.
  bool find(const S& key)
  {
	if (word_map.find(key) != word_map.end()) {
	//	cout << "object found\n" << endl;
		return true;
	} else {
	//	cout << "object NOT found\n" << endl;
		return false;
	}	

    return false;
  }

  // Given a key, this should return a reference to its corresponding value.
  T& operator[](const S& key)
  {
    	return word_map[key];
  }
  
  // Returns all the keys currently existing in the map in a vector.
  vector<S> getKeys()
  {   
    vector<S> keyvector;	
    for (it = word_map.begin(); it != word_map.end(); it++) {
	S key = it->first;
	keyvector.push_back(key);
    }
    return keyvector;
  }

	private:
		typename map<S,T>::iterator it;
		map<S,T> word_map;
};

#endif
