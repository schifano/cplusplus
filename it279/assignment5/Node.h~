#ifndef _NODE_H_
#define _NODE_H_

#include <vector>
#include "STLMap.h"
#include <string>
using namespace std;

class Node
{
 public:
  Node();
  ~Node();
  void addWord(const string& word,int pos);
  vector<string> getAllWords();
  Node * getNext(const char c);

 private:
  vector<string> words;
  MapInterface<char,Node *> *next;
};


#endif
