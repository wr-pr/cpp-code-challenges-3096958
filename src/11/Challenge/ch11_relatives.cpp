// C++ Code Challenges, LinkedIn Learning

// Challenge #11: Finding Relatives
// Write an application that reads a list of people's names in a CSV file and outputs the first pair of people it finds to be possibly related based on their family names.
// Assume that all entries have one name and one family name.
// Entries are separated by commas.
// Names and family names are separated by spaces.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

struct Name {
    std::string first, sur;
    //Name(std::string f, std::string s) : first(f),sur(s){}
    };

int get_first_substr(std::string *str, char sep, std::string *substr)
{
    int c_dot = (*str).find_first_of(sep); 
    *substr = (*str).substr(0,c_dot);
    (*str).erase(0,c_dot+1);
    return c_dot != std::string::npos;
}

int get_next_name(std::string *str, char sep, Name* name)
{
    int c_dot = (*str).find_first_of(sep); 
    std::string substr = (*str).substr(0,c_dot);
    (*str).erase(0,c_dot+1);
    std::string first, sur;
    bool success =  get_first_substr(&substr,' ',&first) &&
           !get_first_substr(&substr,' ',&sur);
    name->first = first;
    name->sur = sur;
    return success && c_dot != std::string::npos;
}

const std::vector<Name> check_relatives(const std::vector<Name> *names)
{
    for (auto n1 {names->begin()}; n1 < names->end(); ++n1)
        for (auto n2 {n1 + 1}; n2 < names->end(); ++n2)
            if (n1->sur == n2->sur) return {*n1, *n2};
    return {};
}

// Finding Relatives, main()
// Summary: This application displays the first pair of possible relatives from a list of names in a CSV file.
int main(){
    std::fstream file ("names.csv", std::ios::in);
    // Read the CSV file.
    std::vector<Name> names, relatives;
    Name r1, r2;
    if(file.is_open()){

        std::string line;
        while (std::getline(file, line)) // Read each line from the file
        {
            Name n_name = {"Hello", "World"};
            while (get_next_name(&line,',',&n_name))
            {
                names.emplace_back(n_name);
            }
        }
        file.close();

        relatives = check_relatives(&names);
        r1 = relatives.at(0);
        r2 = relatives.at(1);
        std::cout << r1.first +" "+ r1.sur + " and " + r2.first + " "+ r2.sur << std::flush;
    }
    else{
        std::cout << "Something went wrong\n" << std::flush;
        return 1;
    }
    //std::cout << "No relatives found.\n\n" << std::flush;    
    return 0;
}
 