//
//  Lecture32-C3_Exception I
//
#include <iostream>

using namespace std;

class invalid_argument {
    
};

int calQuotient(int dividend, int divisor);
class DividByZero: public invalid_argument {
public:
    explicit DividByZero(const string &arg): invalid_argument(arg){};
    const char* what() const noexcept override {
        return "this is a divid by zero exception";
    }
private:
};

int main(int argc, char *argv[]) {
    int num1, num2, result;
    
    for (int i = 0; i < 5; i++)
    {
            cout << "Enter two integers, separated by a space:";
            cin >> num1 >> num2;
        try {
            //
            result = calQuotient(num1, num2);
            cout << num1 << "/" << num2 << " = " << result << endl;
        } catch (DividByZero ) {//catch type should match the throw type, this will handle the exception
            cout << "Caught a DividByZero exception! "  << endl;
        } catch (DivByZero ex) { //DivByZero ex
            cout << "Caught an exception: " << endl;
        }
        
        /*catch (int ex) {
            cout << "Caught a divid by zero exception! "  << ex << endl;
        }
        catch (invalid_argument ex) {//catch type should match the throw type, this will handle the exception
            cout << "Caught an invalid_argument excption: " << ex.what() << endl;
            
        }*/
    }
    return 0;
}

int calQuotient(int dividend, int divisor)
{
    int quotient;
    //if (divisor == 0) throw DividByZero();
    if (divisor == 0) throw DividByZero("DividByZero");
        //throw invalid_argument("DividByZero");
                    //throw -1;
    //throw out an exception when error happens, can be any type of object
    
    quotient = dividend / divisor;
    
    return quotient;
}
