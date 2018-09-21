#include <iostream>
#include <vector>

int main(){

    std::vector<double> numbers(0);

    std::cout << "size: " << numbers.size() << std::endl;

    // size of the internal array that the vector is using
    // it increases in steps
    int capacity = numbers.capacity();
    std::cout << "capacity: " << capacity << std::endl;
    for (int i = 0; i < 10000; i++){
        
        if (numbers.capacity() != capacity){
            capacity = numbers.capacity();
            std::cout << "capacity: " << capacity << std::endl;
        }

        numbers.push_back(i);
    }

    // resize the vector
    numbers.resize(100);
    std::cout << "resized vector"<< std::endl;
    std::cout << "size: " << numbers.size() << std::endl;
    std::cout << "capacity: " << numbers.capacity() << std::endl;
    
    // reserve: increase the size of the internal vector
    numbers.reserve(200000);
    std::cout << "reserved vector"<< std::endl;
    std::cout << "size: " << numbers.size() << std::endl;
    std::cout << "capacity: " << numbers.capacity() << std::endl;
    
    // remove all the elements in the vector
    numbers.clear();
    std::cout << "cleared vector"<< std::endl;
    std::cout << "size: " << numbers.size() << std::endl;
    std::cout << "capacity: " << numbers.capacity() << std::endl;


    return 0;
}