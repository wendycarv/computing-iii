#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

/*
template <class RandomAccessIterator>
void sort (RandomAccessIterator b, RandomAccessIterator e);

template <class RandomAccessIterator, class Compare>
void sort (RandomAccessIterator b, RandomAccessIterator e, Compare comp);
*/
/*
template <class InputIterator, class T>
InputIterator find(InputIterator b, InputIterator e, const T &t);
 */

int main(int argc, const char * argv[]) {
    vector<string> words = {"cat", "hat", "pat", "bat", "mat"};
    
    vector<string>::iterator b, e, p;
    b = words.begin();
    e = words.end();
    
    //find hat and display word after
    p = find(b, e, "hat");
    
    if (p!=e)
        cout << *(p+1) << endl;
    //sort
    sort(b,e);
    cout << "after sorting: " << endl;
    p = find(b, e, "hat");
    
    if (p!=e)
        cout << *(p+1) << endl;
    
    return 0;
}
