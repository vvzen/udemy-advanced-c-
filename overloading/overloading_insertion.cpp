// to compile & run this example:
//      g++ overloading_insertion.cpp -o bin/overloading_insertion && bin/overloading_insertion

#include <iostream>

class Test {

    private:
        int id;
        std::string name;

    public:
        Test(): id(0), name(""){}

        Test(int id, std::string name): id(id), name(name){}
        
        // Copy Constructor
        Test(const Test &other) {
            std::cout << "copy constructor running for " << other.name << std::endl;
            id = other.id;
            name = other.name;
        }

        void print() const {
            std::cout << id << ": " << name << std::endl;
        }

        // = Overloaded
        // we return a reference to this object
        const Test & operator=(const Test &other){

            std::cout << "= assignment running for " << other.name << std::endl;

            id = other.id;
            name = other.name;

            return *this; // this is a pointer, so we dereference it
        }

        // Declare the function that will overload the left bitshift operator
        friend std::ostream & operator<< (std::ostream &out, const Test &test);
};

// Implement the actual overloaded function
std::ostream & operator<< (std::ostream &out, const Test &test){
    out << test.id << ":" << test.name;
    return out;
}


int main(){

    Test test1(10, "Mike");
    Test test2(20, "Bob");

    // Since we overloaded the << operator, we can now do this
    std::cout << test1 << "," << test2 << std::endl;

    return 0;
}