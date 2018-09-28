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
};


int main(){

    Test test1(10, "Mike");
    std::cout << "print test1" << std::endl;
    test1.print();

    Test test2(20, "Bob");

    // this is making a shallow copy, is just copying all the values
    test2 = test1;

    std::cout << "print test2" << std::endl;
    test2.print();

    Test test3;
    // this is equivalent to saying test3 = test2
    test3.operator=(test2);

    std::cout << "print test3" << std::endl;
    test3.print();

    // This is instead is called "Copy Initialisation"
    Test test4 = test1; // here we're running the implicit copy constructor
    std::cout << "print test4" << std::endl;
    test4.print();

    return 0;
}