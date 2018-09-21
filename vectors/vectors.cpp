#include <iostream>
#include <vector>

int main(){

    std::vector<std::string> strings;

    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");

    // different syntax choice for iterating inside a vector

    // 1. classic C like example
    std::cout << "iteration with classic loop" << std::endl;
    for (int i = 0; i < strings.size(); i++){
        std::cout << strings.at(i) << std::endl;
    }

    // 2. with iterator
    std::cout << "iteration with iterator" << std::endl;

    for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++){
        // dereference the iterator to access the pointed element
        std::cout << *it << std::endl;
    }
    
    // 3. c++ 11 magical range for loop
    std::cout << "iteration with c11 auto" << std::endl;

    for (auto i : strings){
        // dereference the iterator to access the pointed element
        std::cout << i << std::endl;
    }

    return 0;
}