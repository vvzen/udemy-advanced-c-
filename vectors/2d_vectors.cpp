#include <iostream>
#include <vector>

int main(){

    // a 2d vector with 3 rows and 4 cols filled with ones
    std::vector< std::vector <int> > grid(3, std::vector<int>(4, 1));

    // log vector elements to stdout
    for (int row = 0; row < grid.size(); row++){
        for (int col = 0; col < grid.at(row).size(); col++){
            std::cout << grid.at(row).at(col) << std::flush;
        }
        std::cout << std::endl;
    }

    return 0;
}