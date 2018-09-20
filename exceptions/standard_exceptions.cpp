#include <iostream>
using namespace std;

class CanGoWrong {
    public:
        CanGoWrong(){

            char * p = new char[9999999999999999];
            delete [] p;
        }
};

int main(){

    try {
        CanGoWrong wrong;
    }
    catch (bad_alloc &e){
        cout << "caught exception: " << e.what() << endl;
    }
    cout << "still running" << endl;

    return 0;
}