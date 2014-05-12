#include "WordManager.h"
#include "AVLMap.h"
#include <ctype.h>
#include <iostream>
using namespace std;

WordManager::WordManager()
{
  manager = new AVLMap<char,Node *>();
}

WordManager::~WordManager()
{
  vector<char> allKeys;

  allKeys = manager->getKeys();

  for (int i=0;i<allKeys.size();i++)
    delete (*manager)[allKeys[i]];

  delete manager;
}

void WordManager::addWord(const string& w)
{
  Node *next;
  string word;

  //convert the word to lower case
  for (int i=0;i<w.length();i++)
  {
    if (isalpha(w[i]))
    {
      word = word + (char)tolower(w[i]);
    }
  }
  

  if (!manager->find(word[0]))
  {
    (*manager)[word[0]] = new Node();
  }
  (*manager)[word[0]]->addWord(word,1);
}

vector<string> WordManager::getWords(const string& prefix)
{
  Node *c;
  int i;
  vector<string> words;

  char ch = (char)tolower(prefix[0]);

  if (manager->find(ch))
  {
    c = (*manager)[ch];
  }    
  else
  {
    return words;
  }



  i = 1;
  while (i<prefix.length())
  {
    c = c->getNext(tolower(prefix[i]));
    if (c==NULL)
      return words; //an empty list
    i++;
  }
  words = c->getAllWords();
  return words;
}
  
