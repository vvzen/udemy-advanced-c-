#include <iostream>
#include <map>

int main(){

    std::map<std::string, int> ages;

    // add values using the overloaded operator
    ages["Mike"] = 40;
    ages["Raj"] = 20;
    ages["Viki"] = 30;
    // keys need to be unique
    ages["Mike"] = 70;

    std::cout << ages["Raj"] << std::endl;

    // we can add to the map using also a pair
    std::pair<std::string, int> peter_pair("Peter", 100);
    ages.insert(peter_pair);

    // or the make_pair function
    ages.insert(std::make_pair<std::string, int>("Paul", 90));


    // if we access the key like this and doesn't exists it will throw a out_of_range exception
    try {
        std::cout << ages.at("Sue") << std::endl;
    }
    catch (std::out_of_range &e){
        std::cout << "Sue is not a key in the map" << std::endl;
    }

    // check if a key is in the map
    if (ages.find("Viki") != ages.end()){
        std::cout << "Found Viki!" << std::endl;
    }
    else {
        std::cout << "Key 'Viki' not found!" << std::endl;
    }
    
    // if we access the key like this and doesn't exists it will be created with a default value of 0
    std::cout << ages["Sue"] << std::endl;


    // iteration through maps is done with an iterator
    for (std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); it++){

        // access key and value using the first and second members
        std::cout << it->first << ":" << it->second << std::endl;

    }
    
    for (std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); it++){

        // access key and value using a pair object
        std::pair<std::string, int> age = *it;
        std::cout << age.first << ":" << age.second << std::endl;

    }

    return 0;
}