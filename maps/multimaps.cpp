#include <iostream>
#include <map>

using namespace std;

int main(){

    multimap<int, string> lookup;

    // there is no index operator overloaded so we need to use insert
    // we can have multiple keys with the same value
    lookup.insert(make_pair(30, "Mike"));
    lookup.insert(make_pair(10, "Viki"));
    lookup.insert(make_pair(30, "Raj"));
    lookup.insert(make_pair(20, "Bob"));

    for (multimap<int, string>::iterator it = lookup.begin(); it != lookup.end(); it++){
        cout << it->first << ": " << it->second << endl;
    }

    cout << endl;

    // find() is just useful to see if a key exists in a multimap
    for (multimap<int, string>::iterator it=lookup.find(20); it != lookup.end(); it++){
        cout << it->first << ": " << it->second << endl;
    }

    cout << endl;
    
    // we want to find all the values with the key = 30
    // a pair of 2 iterators, one pointing to the start of the range, one to the end of it
    pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its = lookup.equal_range(30);
    
    for (multimap<int, string>::iterator it = its.first; it != its.second; it++){
        cout << it->first << ": " << it->second << endl;
    }

    cout << "c++11" << endl;
    
    // USING C++11 magic
    auto its2 = lookup.equal_range(30);
    
    for (auto it = its.first; it != its2.second; it++){
        cout << it->first << ": " << it->second << endl;
    }

    return 0;
}
