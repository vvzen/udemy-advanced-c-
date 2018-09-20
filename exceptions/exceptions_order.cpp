#include <iostream>
#include <exception>
using namespace std;

void goes_wrong(){
    
    bool error_1 = true;
    bool error_2 = false;
    
    if (error_1){
        throw bad_alloc();
    }
    
    if (error_2){
        throw exception();
    }

}

int main(){

    try {
        goes_wrong();
    }
    // this catch block will also catch the children exception (bad_alloc)
    catch (exception &e){
        cout << "catching parent exception: " << e.what() << endl;
    }
    catch (bad_alloc &e){
        cout << e.what() << endl;
    }

    return 0;
}