#include <iostream>
using namespace std;

// an example of a function
// that could encounter an exception
void might_go_wrong(){

    bool error_1 = false;
    bool error_2 = true;

    if (error_1){
        throw "something went wrong";
    }

    if (error_2){
        throw string("something else went wrong");
    }

}

void uses_might_go_wrong(){
    might_go_wrong();
}

int main(){

    try {
        uses_might_go_wrong();
    }
    catch (int e){
        cout << "error code: " << e << endl;
    }
    catch (char const * e){
        cout << "error message: " << e << endl;
    }
    catch (string &e){
        cout << "error message: " << e << endl;
    }
    cout << "still running" << endl;

    return 0;
}