#include <iostream>
// streams are objects that we can write to or read from
#include <fstream>

int main(){

    std::string file_name = "stats.txt";
    std::ifstream stats_file;

    stats_file.open(file_name);

    // check if could open the file successfully
    if (!stats_file.is_open()){
        
        std::cout << "Could not open file: " << file_name << std::endl;
        return 1;
        
    }

    // while we haven't reached the end of file
    while (!stats_file.eof()){

        std::string line;
        
        // read a line using a special character as delimiter
        getline(stats_file, line, ':');

        int population;

        stats_file >> population;
        
        // read whatever whitespace we have (skips the \n on the next getline() read)
        stats_file >> std::ws;

        std::cout << "'" << line << "' - '" << population << "'" << std::endl;
    }
    
    stats_file.close();

    return 0;
}