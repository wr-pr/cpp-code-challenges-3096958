// C++ Code Challenges, LinkedIn Learning

// Challenge #12: Age in Days Calculator
// Write an application that asks the user's birth date and responds with the user's age in days. 
// If the user claims to be over 120 years old, output a message calling the bluff.

#include <iostream>
#include <string>
#include <ctime>
#include <vector>

bool isLeapYear(int year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Age in Days, main()
// Summary: This application asks the user's birth date and prints their age in days.
int main(){
    int birth_y, birth_m, birth_d, today_y, today_m, today_d, age = 0;

    std::cout << "Enter your birth date's month as a number: " << std::flush;
    std::cin >> birth_m;
    std::cout << "Enter your birth date's day: " << std::flush;
    std::cin >> birth_d;
    std::cout << "Enter your birth date's year: " << std::flush;
    std::cin >> birth_y;
    
    if(birth_m < 1)
        birth_m = 1;
    if(birth_m > 12)
        birth_m = 12;

    std::time_t currentTime = std::time(nullptr);
    // Convert to local time
    std::tm* localTime = std::localtime(&currentTime);
    // Extract year, month, and day
    today_y = localTime->tm_year + 1900; // Years since 1900
    today_m = localTime->tm_mon + 1;    // Month index is zero-based
    today_d = localTime->tm_mday;         // Day of the month

    std::vector<int> days_in_birth = {31, isLeapYear(birth_y) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::vector<int> days_in_today = {31, isLeapYear(today_y) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    //age = 365*(today_y-birth_y-1);
    for (int i {birth_y+1}; i < today_y; ++i) if (isLeapYear(i)) ++age;
    for (int i {0}; i < today_m-1; ++i) age += days_in_today.at(i);
    for (int i {11}; i > birth_m-1; --i) age += days_in_birth.at(i);
    age += today_d;
    age += days_in_birth.at(birth_m-1) - birth_d -1;

    if(age < 43830)
        std::cout << "You are " << age << " days old.";
    else
        std::cout << "Come on. You can't be " << age << " days old!";
    std::cout << "\n\n" << std::flush;
}
