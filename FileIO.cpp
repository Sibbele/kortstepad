// programma dat van een file
// het aantal regels en het aantal woorden telt

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  string fname;
  cout << "filename: ";
  cin >> fname;
  ifstream file(fname.c_str());  // conversie naar C-string
  int linecount = 0, wordcount = 0;
  while(file.good())
  {
    string line;
    getline(file, line);
    stringstream ss(line);       // treat a string object like a stream, and use all stream functions and operators on it.
    while(ss.good())
    {
      string s;
      ss >> s;                   // extraction operator; extract formatted input
      wordcount++;
    }
    linecount++;
  }
  cout << "lines: " << linecount << endl << "words: " << wordcount << endl;
}
