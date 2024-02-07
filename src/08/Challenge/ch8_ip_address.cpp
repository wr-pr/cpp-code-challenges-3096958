// C++ Code Challenges, LinkedIn Learning

// Challenge #8: IP Address Validation
// Write an application that reads a string from the terminal and responds with a message indicating whether the string is a valid IP address or not.
// Assume decimal IP addresses.
// 158.25.0.33
// All numbers between 0 and 255.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// is_valid_ip()
// Summary: This function validates an IP address.
// Arguments:
//           ip: The string to analyze with a potential ip address.
// Returns: A boolean value. True for valid ip addresses, false otherwise.
bool is_valid_ip(std::string ip){
    bool is_valid {true};
    std::size_t p_dot;
    int n;
    std::string substr;
    for (int i {0}; i<4;++i)
    {
        try
        {
            p_dot = ip.find_first_of('.');
        }
        catch(const std::exception& e)
        {
            is_valid = false;
            break;
        }
        substr = ip.substr(0,p_dot);
        ip.erase(0,p_dot+1);
        bool temp = std::all_of(substr.begin(), substr.end(), ::isdigit);
        if (!std::all_of(substr.begin(), substr.end(), ::isdigit))
        {
            is_valid = false;
            break;
        }
        n = std::stoi(substr);
        if (n < 0 || 255 < n)
        {
            is_valid = false;
            break;
        }
    }
    return is_valid;
}

// Main function
int main(){
    std::string s;
    
    std::cout << std::endl << "Enter an IP address in decimal: " << std::flush;
    std::getline(std::cin,s);
    std::cout << " \n" << s << (is_valid_ip(s) ? " is" : " is not" ) << " a valid IP address.\n\n";
    return 0;
}
