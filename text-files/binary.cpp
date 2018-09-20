#include <iostream>
// streams are objects that we can write to or read from
#include <fstream>

// the only difference between a struct and a class
// is that a struct members are public by default
// structs are generally used to write binary files

// structs are padded in memory, so we use the #pragma pack directive.
// this directive says to allign the data and whatever follows to single byte boundaries
#pragma pack(push, 1)

struct Person {

    // a string is a pointer to a memory address containing the actual characters
    // that's why we're going to use a char array
    char name[50]; // 50 bytes
    int age; // is 4 bytes
    double height; // is 8 bytes
};

// turn off packing
#pragma pack(pop)

int main(){

    Person someone = {"Samwise", 26, 0.76};

    std::cout << sizeof(Person) << std::endl;

    std::string file_name = "test.bin";

    std::ofstream out_file;
    // open the file as a raw binary file
    out_file.open(file_name, std::ios::binary);

    ///////// WRITE BINARY FILE /////////
    if (out_file.is_open()){

        // write() expects a char * in order to write the data that's why we cast it
        // it also expects how many bytes we want to write
        // out_file.write((char *) &someone, sizeof(Person)); // OLD WAY

        out_file.write(reinterpret_cast<char *>(&someone), sizeof(Person)); // NEW, BETTER WAY

        out_file.close();
    }
    else {
        std::cout << "Unable to write file: " << file_name << std::endl;
    }
    
    ///////// READ BINARY FILE /////////
    Person someone_else = {};
    
    std::ifstream in_file;
    in_file.open(file_name, std::ios::binary);

    if (in_file.is_open()){

        in_file.read(reinterpret_cast<char *>(&someone_else), sizeof(Person));

        in_file.close();
    }
    else {
        std::cout << "Unable to read file: " << file_name << std::endl;
    }

    std::cout << someone_else.name << ", " << someone_else.age << ", " << someone_else.height << std::endl;

    return 0;
}