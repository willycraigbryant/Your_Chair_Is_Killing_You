//
// Created by William Bryant on 4/26/18.
//

#include <iostream>                         // cout and endl
#include <string>                           // strings
#include <vector>                           // vectors
#include <iomanip>

void display_current_time_by_seconds()
{
    // Take the current time "now()", add 1 second to it, and store it in a time_point object called "tend".
    std::chrono::steady_clock::time_point tend = std::chrono::steady_clock::now() + std::chrono::seconds(1);
    // Create boolean to keep track when time "tend" had been reached.
    bool displayed = false;
    // Go into a loop that will end once time "tend" has been reached.
    while (!displayed)
    {
        // Check to see if time "tend" is reached or passed.
        if (std::chrono::steady_clock::now() >= tend)
        {
            // Take the current time and store it in variable "now".
            auto now = std::chrono::system_clock::now();
            // Convert "now" into a time_t type so it can be displayed.
            auto now_c = std::chrono::system_clock::to_time_t(now);
            // Display the current time.
            std::cout << std::put_time(std::localtime(&now_c), "%c") << '\n';
            // The current time has been displayed
            displayed = true;
        }
        else
            // If current time not displayed, continue.
            continue;
    }
}

// Introduction to the program
void opening_intro()
{
    std::cout << "\t\tYour Chair is Killing You!\t\t" << std::endl;
    std::cout << "Did you know sitting down for long periods\n" << std::endl;
    std::cout << "of time is very dangerous? 6 hours of sitting\n" << std::endl;
    std::cout << "increases your chances of dying by 40%!\n" << std::endl;
    std::cout << "That's why we are here! to remind YOU to stand\n" << std::endl;
    std::cout << "up and decrease dozens of health issues.\n" << std::endl;

}

// Tells the use about "Your Chair is Killing You!"
void about_program()
{
    std::cout << "Our program is simple. We run a timer that" << std::endl;
    std::cout << "will remind you to stand up every 15 minutes" << std::endl;
    std::cout << "to give your self a breather and keep your" << std::endl;
    std::cout << "blood flowing. We save your progress and you" << std::endl;
    std::cout << "can even customize your alerts for standing." << std::endl;
}

// Used got referring to elements in vectors
std::string& ref_to_vector(std::vector<std::string>& vec, int i)
{
    return vec[i];
}
