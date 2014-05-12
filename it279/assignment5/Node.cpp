#include "Node.h"
#include "AVLMap.h"
#include <iostream>
using namespace std;

Node::Node()
{
  next = new AVLMap<char,Node *>();
}

Node::~Node()
{
  vector<char> allKeys;

  allKeys = next->getKeys();

  for (int i=0;i<allKeys.size();i++)
  {
    delete (*next)[allKeys[i]];
  }
  delete next;
}

vector<string> Node::getAllWords()
{
  //get all words ending here and where these words are prefixes
  vector<string> w;
  int i;
  int j;

 

  for (i=0;i<words.size();i++)
    w.push_back(words[i]);

  vector<char> allKeys;


  allKeys = next->getKeys();

  for (j=0;j<allKeys.size();j++)
  {
    vector<string> wtemp = (*next)[allKeys[j]]->getAllWords();
    for (i=0;i<wtemp.size();i++)
      w.push_back(wtemp[i]);
  }
  return w;  
}

Node * Node::getNext(const char c)
{
  if (next->find(c))
    return (*next)[c];
  else
    return NULL;
}

void Node::addWord(const string& word,int pos)
{

  if (pos<word.length())
  {
    Node * n = getNext(word[pos]);
    if (n==NULL)
      (*next)[word[pos]] = new Node();
    (*next)[word[pos]]->addWord(word,pos+1);
  }
  else
    words.push_back(word);
}



  
