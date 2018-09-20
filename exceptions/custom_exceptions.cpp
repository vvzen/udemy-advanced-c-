#include <iostream>
#include <exception>
using namespace std;

// a custom class that inherits from the c++ exception class
class MyException : public exception {

    public:
        // this method cannot throw an exception
        // const throw() alts the program at runtime
        virtual const char * what() const throw(){
            return "Something bad happened";
        }
};

class Test {

    public:
        void goes_wrong() throw() {
            throw MyException();
        }
};

int main(){

    Test test;

    try {
        test.goes_wrong();
    }
    catch (MyException &e){
        cout << "exception thrown: " << e.what() << endl;
    }

    return 0;
}