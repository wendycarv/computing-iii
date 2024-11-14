#include <iostream>
using namespace std;

class B{
public:
    B():bPtr (new int[5]){
        cout << "allocates 5 ints\n";
    }
    virtual ~B(){
        delete []bPtr;
        cout <<"deallocates 5 ints\n";
    }
private:
    int *bPtr;
};

class D:public B{
public:
    D():B(), dPtr(new int [1000]){
        cout <<"allocates 1000 ints\n";
    }
    ~D(){
        delete []dPtr;
        cout << "deallocates 1000 ints\n";
    }
private:
    int *dPtr;
};

int main(int argc, const char * argv[])
{
    B* bPtr = new D;
    delete bPtr;
    
    return 0;
}
