#include <iostream>
// streams are objects that we can write to or read from
#include <fstream>

int main(){

    std::string file_name = "text.txt";
    std::ifstream in_file;

    in_file.open(file_name);

    if (in_file.is_open()){
        
        std::string line;

        // while we haven't reached the end of file
        // we can also use just 
        //      while (!in_file){}
        while (!in_file.eof()){
            
            getline(in_file, line);

            std::cout << line << std::endl;
        }
        in_file.close();
    }
    else {
        std::cout << "Could not open file: " << file_name << std::endl;
    }

    return 0;
}