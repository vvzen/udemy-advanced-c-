#include <iostream>
#include <map>

class Person {

    private:
        int age;
        std::string name;

    public:

        // constructor
        Person(std::string name, int age) :
            name(name), age(age){
        }

        // this method required for the map structure to make the comparisons between Person objects
        // since a map always has the keys sorted
        bool operator<(const Person &other) const {
            // we take into account the name, and if the name is equal, the age
            if (name == other.name){
                return age < other.age;    
            }
            else {
                return name < other.name;
            }
        }

        // the const keyword after the method means we're not going to change the current object
        void print() const {
            std::cout << name << ": " << age << std::flush;
        }
};


int main(){

    // using our custom object as a key in the map
    std::map<Person, int> people;

    people[Person("Mike", 30)] = 30;
    people[Person("Mike", 444)] = 123;
    people[Person("Sue", 40)] = 40;
    people.insert(std::make_pair(Person("Ray", 20), 20));

    for (std::map<Person, int>::iterator it = people.begin(); it != people.end(); it++){

        std::cout << it->second << ": " << std::flush;

        // the iterator return first as a const Person
        // so the print() method needs to be a const method
        it->first.print();
        std::cout << std::endl;

    }

    return 0;
}