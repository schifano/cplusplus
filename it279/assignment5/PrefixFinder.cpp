#include "WordManager.h"
#include <iostream>
#include <fstream>
#include "AVLMap.h"
#include <map>
using namespace std;

int main(int argc,char *argv[])
{
  if (argc!=2)
  {
    cout << "Please provide the input file for dictionary"<<endl;
    return -1;
  }

  WordManager wmanager;
  string word;

  ifstream fin(argv[1]);

  if (!fin.is_open())
  {
    cout <<"File "<<argv[1]<<" not found!"<<endl;
    return -1;
  }

  while (fin >> word)
  {
    wmanager.addWord(word);
    }
  fin.close();

  //try it out

  bool complete = false;
  while (!complete)
  {
    cout <<"Enter a word"<<endl;
    cin >> word;
    vector<string> words = wmanager.getWords(word);
    cout <<"No. of words with prefix \""<<word<<"\": "<<words.size()<<endl;
    for (int i=0;i<words.size();i++)
    cout << (i+1) <<". "<< words[i] <<endl;

    cout <<"Would you like another try? (yes/no):";
    cin >> word;
    if (word.compare("no")==0)
      complete = true;
  }


}


      
