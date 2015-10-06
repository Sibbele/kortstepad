// kortstepad algorithme
// Sibbele Oosterhaven

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class KPad
{

private:
  const int verweg = 1000000;
  string filename;
  map<string, int> plaatsen;
  map<pair<string, string>, int> afstanden;
  map<pair<string, string>, string> routes;

public:
  KPad(string fname)
  {
    filename = fname;
  }

  void fillMap(void)
  {
    string fname = filename;
    ifstream file(fname.c_str());  // conversie naar C-string
    int linecount = 0, wordcount = 0;
    while(file.good())
    {
      string line;
      getline(file, line);
      stringstream ss(line);   // treat a string object like a stream, and use all stream functions and operators on //it.
      while(ss.good())
      {
        string p1, p2;
        int a;
        ss >> p1 >> p2 >> a;   // extraction operator; extract formatted input
        cout  << p1 << " - " << p2 << " = " << a << endl;   //printf("%s %s =  %s\n", p1.c_str(), p2.c_str(), a.c_str())
        if (p1.empty() || p2.empty() or (a == 0))
          afstanden.insert(make_pair(make_pair(p1, p2), a));
        //plaatsen.insert(make_pair(p1, a));
        //plaatsen.insert(pair<string, int>(p1, a));
      }
      linecount++;
    }
    cout << "lines: " << linecount << endl;
  }

  void printMap(void)
  {
    //for (map<pair<string, string>, int> it = afstanden.begin(); it != afstanden.end(); it++)
    //  cout << it->first << " => " << it->second << endl;
  }

  int afstand(string plaats1, string plaats2)
  {
  }

  string route(string plaats1, string plaats2)
  {
  }

};


int main(int argc, char*argv[])
{
  if(argc != 1) {  // 2
    cout << "usage: floyd <filename>" << endl;
    return 0; 
  }

  //KPad kp(argv[1]);  // constructor 
  KPad kp("afstanden");  // constructor
  
  //for(;;) {
    //string plaats1 = ask("plaats1 = ");
    //string plaats2 = ask("plaats2 = ");

    kp.fillMap();
    kp.printMap();

    cout << "hun afstand is " << endl;
    //cout << "hun afstand is "<<kp.afstand(plaats1, plaats2)<< endl;
    //cout << "via de route: " <<kp.route(plaats1, plaats2)  << endl;
  //}
}
