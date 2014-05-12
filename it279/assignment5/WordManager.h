#ifndef _WORDMANAGER_H_
#define _WORDMANAGER_H

#include <string>
#include "MapInterface.h"
#include <vector>
using namespace std;
#include "Node.h"

class WordManager
{
 public:
  WordManager();
  ~WordManager();
  void addWord(const string& word);
  vector<string> getWords(const string& prefix);
 private:
  MapInterface<char,Node *> *manager;
};

#endif
