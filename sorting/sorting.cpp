#include <iostream>
#include <vector>

class Test {

    private:
        int id;
        std::string name;

    public:
        // copy constructor
        Test(const Test &other){
            name = other.name;
            id = other.id;
            std::cout << "running copy constructor" << std::endl;
        }
        // default constructor
        Test() : id(0), name(""){}

        // name constructor
        Test(int id, std::string name) : id(id), name(name){}

        void print() const {
            std::cout << id << ":\t" << name << std::endl;
        }

        // we need the < operator in order to sort the Test object
        bool operator<(const Test &other) const {

            if (name != other.name){
                return id < other.id;
            }
            else {
                return name < other.name;
            }
        }

        // this function will now be able to access private members of this class, because it is a friend
        friend bool compare_test(const Test &a, const Test &b);

        // destructor
        ~Test(){}
};

// a custom function used to compare
bool compare_test(const Test &a, const Test &b){
    return a.name < b.name;
}


int main(){
    
    std::vector<Test> tests;

    // this is going to use the copy constructor
    std::cout << "push back object" << std::endl;
    tests.push_back(Test(5, "Mike"));
    tests.push_back(Test(10, "Sue"));
    tests.push_back(Test(7, "Raj"));
    tests.push_back(Test(3, "Vicky"));

    // std::cout << "emplace back" << std::endl;
    // tests.emplace_back(Test(22, "Valerio"));
    // tests.emplace_back(Test(60, "James"));

    // we can use this sort if our class overloads the < operator
    std::sort(tests.begin(), tests.end());

    // otherwise, we can use a custom function to compare the two objects and supply it (function pointer)
    std::sort(tests.begin(), tests.end(), compare_test);

    for (auto it = tests.begin(); it != tests.end(); it++){
        it->print();
    }

    return 0;
}
