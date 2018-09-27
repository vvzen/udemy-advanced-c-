#include <iostream>
#include <stack>
#include <queue>

class Test {
    private:
        std::string name;

    public:

        // copy constructor
        Test(Test const &other) {
            name = other.name;
            std::cout << "\trunning copy constructor of " << name << std::endl;
        }

        Test(std::string name) : name(name){}

        ~Test(){
            std::cout << "\trunning destructor of " << name << std::endl;
        }

        void print() const {
            std::cout << name << std::endl;
        }
};

int main(){

    /////////////////////////////////////////////// 
    //////////////////// STACK //////////////////// 
    /////////////////////////////////////////////// 
    std::cout << "learning stacks" << std::endl;

    // LIFO: last in first out
    std::stack<Test> test_stack;
    
    // When we add this objects to the stack, they are copied and then destroyed
    test_stack.push(Test("Mike"));
    test_stack.push(Test("John"));
    test_stack.push(Test("Sue"));

    // Get the last element as a copy
    Test test = test_stack.top();
    test.print();

    // Remove last element (it destroys it)
    test_stack.pop(); // Sue is now destroyed, we can no longer use it in a reliable way

    /*
    // There is no way to iterate in a stack, since it's made for a different purpose
    // This is a kind of way of iterating
    std::cout << "looping" << std::endl;
    while (test_stack.size() > 0){
        Test &test2 = test_stack.top();
        test2.print();
        test_stack.pop();
    } */

    // In order to optimize things, we can instead get a reference to the object
    Test &test1 = test_stack.top();
    test1.print();

    /////////////////////////////////////////////// 
    //////////////////// QUEUE //////////////////// 
    /////////////////////////////////////////////// 
    std::cout << "learning queues" << std::endl;

    // FIFO: first in first out
    std::queue<Test> test_queue;

    // When we add this objects to the stack, they are copied and then destroyed
    test_queue.push(Test("Mike"));
    test_queue.push(Test("John"));
    test_queue.push(Test("Sue"));

    Test &test3 = test_queue.back();
    test3.print();

    std::cout << "application is closing, clearing stacks and queues" << std::endl;

    return 0;
}