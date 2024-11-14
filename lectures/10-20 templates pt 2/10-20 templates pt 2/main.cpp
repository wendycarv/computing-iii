//
//  C3_Lecture19
// class templates
#include <iostream>
using namespace std;

//TODO: define a pair class that contains a pair of values of the same type
template <class T>
class Pair{
public:
    
    Pair(T iVal1, T iVal2):val1(iVal1), val2(iVal2){}
    T getFirst(void) const;
    T getSecond(void) const;
    
    void setFirst(T newValue);
    void setSecond(T newValue);

private:
    T val1;
    T val2;
};

template <class T>
T addUp(const Pair<T>& aPair);

int main(int argc, char * argv[]) {

    Pair<int> intPair(2, 3);
    addUp(intPair);
    
    Pair<char> charPair('A', 'B');
    addUp(charPair);
    
    Pair<void *> pointerPair(&intPair, &charPair);
    //addUp(pointerPair);//doesn't work!
    
    return 0;
}

/*
 precondition: + should be defined for the data type passed in
 */
template <class T>
T addUp(const Pair<T>& aPair) {
    return aPair.getFirst() + aPair.getSecond();
}

//
template <typename T>
T Pair<T>::getFirst(void) const {
    return val1;
}
template <typename T>
T Pair<T>::getSecond(void) const {
    return val2;
}

template <typename T>
void Pair<T>::setFirst(T newValue) {
    val1 = newValue;
}

template <typename T>
void Pair<T>::setSecond(T newValue) {
    val2 = newValue;
}
