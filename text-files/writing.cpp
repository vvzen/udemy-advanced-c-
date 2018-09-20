#include <iostream>
// streams are objects that we can write to or read from
#include <fstream>

int main(){

    std::ofstream out_file; // ofstream is an outputfile stream
    std::string out_file_name = "text.txt";

    out_file.open(out_file_name);
    //out_file.open(out_file_name, std::ios_base::app); // if we want to append to the file

    if (out_file.is_open()){
        out_file << "Hello there";
        out_file << "123" << std::endl;
        out_file << 123 << std::endl;
        out_file.close();
    }
    else {
        std::cout << "Could not create file: " << out_file_name << std::endl;
    }

    return 0;
}