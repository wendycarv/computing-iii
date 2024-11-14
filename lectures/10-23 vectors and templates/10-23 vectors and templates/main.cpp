//
//  C3_Lecture20
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    vector<char> v = {'A', 'B', 'C', 'D'};
    
    //access elements using index, random access
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    
    //access elements using iterator
    vector<char>::iterator p;
    for (p = v.begin(); p != v.end(); p++) {
        cout << *p << endl;
    }
    
    auto p = v.begin();
    
    for(; p != v.end(); p++)
    {
        cout << *p << endl;
    }
    
    //v.begin(): returns an iterator for the container v, which references the 1st item in v
    //v.end(): returns a sentinel that indicates â€œone past the endâ€ (doesn't have a value)

    return 0;
}
