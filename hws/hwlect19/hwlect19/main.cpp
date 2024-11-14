#include <iostream>
using namespace std;

template <class SUMMABLE>
SUMMABLE sum(const SUMMABLE *array, int size);


int main(int argc, char *argv[])
{
    
    double arrOne[] = {1.7, 3.3, 2.4};
    int arrTwo[] = {1, 2, 3, 4, 5};
    
    cout << "sum of array #1 is: " << sum(arrOne, sizeof(arrOne)/8) << endl;
    cout << "sum of array #2 is: " << sum(arrTwo, sizeof(arrTwo)/4) << endl;
    
    return 0;
}

//Preconditions: valid array and arrSize, array elements must be summable (a type that supports addition), + operator should be defined
//Postcondition: function will return a value of the same type as the elements of the array, return value is the sum of the numerical values in the array, and the original array and its size remain unchanged
template <class SUMMABLE>
SUMMABLE sum(const SUMMABLE *array, int size)
{
    int i;
    SUMMABLE sum = 0;
    
    for (i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}
