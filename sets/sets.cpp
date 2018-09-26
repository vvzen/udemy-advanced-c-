#include <iostream>
#include <set>

class Test {
    
    private:
        int id;
        std::string name;

    public:
        Test(): id(0), name(""){} // it's good practice to add a default constructor
        Test(int id, std::string name): id(id), name(name){}

        void print() const {
            std::cout << id << ": " << name << std::endl;
        }

        // we overload the < operator in order to use this class into a set
        bool operator<(const Test &other) const{
            if (name != other.name){
                return name < other.name;
            }
            else {
                return id < other.id;
            }
        }
};

int main(){

    // a set of ints
    std::set<int> numbers;

    // a set does not allow for duplicates and is always sorted
    numbers.insert(1);
    numbers.insert(1);
    numbers.insert(3);
    numbers.insert(4);
    numbers.insert(2);

    for (std::set<int>::iterator it = numbers.begin(); it != numbers.end(); it++){
        std::cout << *it << std::endl;
    }

    // find() is used to check where a value is in a set
    std::set<int>::iterator itFind = numbers.find(3);
    if (itFind != numbers.end()){
        std::cout << "found: " << *itFind << std::endl;
    }

    // count() is used to check if a value is in a set (returns 1 or 0)
    if (numbers.count(3)){
        std::cout << "number " << 3 << " found" << std::endl;
    }

    // a set of custom objects
    std::set<Test> tests;
    tests.insert(Test(1, "Pippo"));
    tests.insert(Test(2, "Mike"));
    tests.insert(Test(3, "George"));
    tests.insert(Test(33, "George"));
    tests.insert(Test(4, "Joe"));

    for (std::set<Test>::iterator it = tests.begin(); it != tests.end(); it++){
        it->print();
    }


    return 0;
}