#include <iostream>
#include <vector>
#include <map>

int main(){

    std::map<std::string, std::vector<int> > scores;

    scores["Mike"].push_back(10);
    scores["Mike"].push_back(20);
    scores["Vicky"].push_back(15);
    scores["Vicky"].push_back(25);

    // iterate through the keys
    for (auto it = scores.begin(); it != scores.end(); it++){
        
        std::string name = it->first;
        std::vector<int> score_list = it->second;

        std::cout << name << ": " << std::flush;

        for (auto it2 = score_list.begin(); it2 != score_list.end(); it2++){
            
            std::cout << *it2 << " " << std::flush;

        }

        std::cout << std::endl;
    }


    return 0;
}