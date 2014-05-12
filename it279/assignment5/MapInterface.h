#ifndef _MAPINTERFACE_H_
#define _MAPINTERFACE_H_

#include <vector>
#include <string>
using namespace std;

template<class S,class T>
class MapInterface
{
 public:
  virtual T& operator[](const S& key)=0;
  virtual bool find(const S& key)=0;
  virtual vector<S> getKeys()=0;
};

#endif
