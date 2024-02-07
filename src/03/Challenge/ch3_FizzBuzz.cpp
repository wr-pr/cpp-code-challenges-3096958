// C++ Code Challenges, LinkedIn Learning

// Challenge #3: FizzBuzz
// Write an application that plays FizzBuzz.
// Print an integer number sequence starting at 1, replacing multiples of 3 by "Fizz", multiples of 5 by "Buzz", and multiples of 3 and 5 by "FizzBuzz".
// The user enters the last number in the sequence.

#include <iostream>
#include <string>

// FizzBuzz, main()
// Summary: This application runs on the main function.
int main(){
    int n; // How many numbers to include in the sequence.
    
    std::cout << "Enter a positive integer: " << std::flush;
    std::cin >> n;

    // Write your code here
    std::string arr = "1";
    for (int i {2}; i<n;++i)
    {
        bool mod3 {i%3==0}, mod5 {i%5==0};
        arr.append(" ");
        if (!mod3 && !mod5)
        {
            arr.append(std::to_string(i));
            continue;
        }
        if (mod3) arr.append("Fizz");
        if (mod5) arr.append("Buzz");
    }
    std::cout << arr << std::endl << std::flush;
    return 0;
}
