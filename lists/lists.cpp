#include <iostream>
#include <list>

// a linked list can be used to insert element at every position
// not just at the end of the container, as we do with vectors
// each node in a list is linked to the previous and next node in the list

int main(){

    std::list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_front(0);

    std::cout << "for" << std::endl;
    // insert an element
    // to iterate in a list we need an iterator
    // because there is no such thing as an index
    for (std::list<int>::iterator it = numbers.begin(); it != numbers.end();){

        if (*it == 2){
            numbers.insert(it, 1234);
        }

        if (*it == 1){
            // delete an element
            it = numbers.erase(it);
            // decrease the iterator because after the erase operation
            // the iterator will point to the next element
            // it--;
        }
        else {
            it++;
        }
    }

    for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); it++){
        std::cout << "\t" << *it << std::endl;
    }

    // we can do the same thing with a while

    std::list<int> other_numbers;

    other_numbers.push_back(5);
    other_numbers.push_back(6);
    other_numbers.push_back(7);
    other_numbers.push_front(4);

    std::cout << "while" << std::endl;
    std::list<int>::iterator another_it = other_numbers.begin();
    while (another_it != other_numbers.end()){

        if (*another_it == 5){
            other_numbers.insert(another_it, 1234);
        }

        // if (*another_it == 5){
        //     // delete an element
        //     another_it = other_numbers.erase(another_it);
        //     // decrease the iterator because after the erase operation
        //     // the iterator will point to the next element
        //     // it--;
        // }
        another_it++;
    }

    for (std::list<int>::iterator it = other_numbers.begin(); it != other_numbers.end(); it++){
        std::cout << "\t" << *it << std::endl;
    }

    return 0;
}