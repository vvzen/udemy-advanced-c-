#include <iostream>
#include <map>

class Person {

    private:
        std::string name;
        int age;

    public:

        // we need this constructor without parameters for the map
        Person() : name(""), age(0){
        
        }

        Person(const Person &other){
            
            std::cout << "Copy constructor running!" << std::endl;
            name = other.name;
            age = other.age;
        }

        Person(std::string name, int age) :
            name(name), age(age){

        }

        void print(){
            std::cout << name << ": " << age << std::endl;
        }
};

int main(){

    std::map<int, Person> people;

    people[0] = Person("Mike", 40);
    people[41] = Person("Viki", 30);
    people[25] = Person("Ray", 20);
    
    people.insert(std::make_pair(42, Person("Bob", 45)));
    people.insert(std::make_pair(42, Person("Sue", 24)));


    for (std::map<int, Person>::iterator it = people.begin(); it != people.end(); it++){
        std::cout << it->first << ": " << std::flush;
        it->second.print();
    }

    return 0;
}