#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
#include <vector>
#include <map>
using namespace std;

int main(int argc, const char *argv[])
{
    /*
    set<string> cities = {"Boston", "Andover", "Lowell", "Chelmsford"};
    cities.insert("Lowell");
    set<string>::iterator f = cities.find ("New York");
    if (f == cities.end())
    {
        //cannot find the key
        cout << "Can't find the name" << endl;
    } else {
        //can find it
        cout << "Found it!" << endl;
    }
    set<string>::iterator p = cities.begin();
    for (; p != cities.end(); p++)
    {
        cout << *p << endl;
    }
    
    //ranged for loop
    for (string eachElement:cities) //string or auto &eachElement
    {
        cout << eachElement << endl;
    }
     */
    
    //TODO: create a map
    map<string, unsigned> cities;
    cities["Boston"] = 11111;
    cities["Andover"] = 22222;
    cities["Lowell"] = 33333;
    //cities["Chelmsford"] = 44444;

    cities.insert(pair<string, unsigned>("Chelmsford", 44444));
    //TODO: print with iterator:
    map<string, unsigned>::iterator p;
    
    for (p = cities.begin(); p != cities.end(); p++)
    {
        cout << (*p).first << ", " << p->second << endl;
    }
    
    //TODO: ranged for loop to print again
    
    //eachEle: std::pair
    for (auto eachEle:cities)
    {
        eachEle
    }
    return 0;
}
