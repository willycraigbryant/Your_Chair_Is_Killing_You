/*******************************************************************************
 * Program: Your Chair is Killing You!
 * Programmer: William Bryant
 * Date: 4-21-2018
 * Development: Make in CLion on MAC OS X High Sierra
 * INFO:
 * "Your Chair is Killing You!" is a program that will remind the user when
 * they need to stand up from their chair.
 * NOTE:
 * If you are troubling shooting to just checking out functionality, there
 * is an option to decrease the default sitting time. Lowest you can go is
 * one minute.
 ******************************************************************************/

/*===================Includes=======================*/
#include <iostream>                         // cout and endl
#include <string>                           // strings
#include <vector>                           // vectors
#include <chrono>                           // chrono::system clock
#include <ctime>                            // localtime
#include <time.h>                           // time_t and struct tm
#include <iomanip>                          // put_time
#include <cstdlib>                          // units library
#include <boost/lexical_cast.hpp>           // use boost
#include "functions.h"                      // functions library
/*==================================================*/

int main()
{
    /*=========Declare & Initialize Variables===========*/
    std::vector<std::string> user_info;     // Where we store user information
    int num_of_user_stands = 3;             // How many times the user stood up
    std::vector<std::string> sitting_data;  // What times the user stood up
    std::string user_name;                  // Store their name
    std::string user_sex;                   // Store there sex
    std::string user_age;                   // Store there age
    std::string new_input;                  // For changing user information
    int alarm_time = 15;                    // How many minutes alarm will go off
    int choice;                             // For number inputs
    char input;                             // For letter inputs
    time_t rawtime;                         // Getting current time
    struct tm * timeinfo;                   // Structure with calendar, date and time
    int* Pointer = nullptr;                 // Pointer for changing int values
    /*==================================================*/

    // Start program with an intro and information about sitting
    opening_intro();

    // Ask for user's information
    std::cout << "Please provide your information below.\n";
    std::cout << "Name: \n";
    getline(std::cin, user_name);
    std::cout << "Sex: \n";
    getline(std::cin, user_sex);
    std::cout << "Age: \n";
    // don't use get line since its just a number
    std::cin >> user_age;

    // Put user's information in vector
    user_info.push_back(user_name);
    user_info.push_back(user_sex);
    user_info.push_back(user_age);
    // Show elements in vector by reference
    for (int i = 0; i < user_info.size(); ++i)
    {
        std::cout << ref_to_vector(user_info, i) << std::endl;
    }
    // Tell the user what the program will do and what it is about
    about_program();

    /*============================Main Program Loop================================*/
    // Put user in main program loop
    while(true)
    {
        // Go into main menu
        do {
            std::cout << "\tMain Menu\t" << std::endl;
            std::cout << "1 - Start Sitting Session\n";
            std::cout << "2 - Change User Info\n";
            std::cout << "3 - About and Help\n";
            std::cout << "4 - Quit\n";
            // Ask for input and store in choice
            std::cout << "Please choose an option: \n";
            std::cin >> choice;
            std::cin.clear();
            std::cin.get();
            // Use keyword switch to check and compare the inputted value
            switch (choice)
            {
                case 1:
                    std::cout << "Starting sit session...\n";
                    break;
                case 2:
                    std::cout << "Accessing User Information...\n\n";
                    break;
                case 3:
                    std::cout << "Going to About and Help Page...\n";
                    break;
                case 4:
                    std::cout << "Leaving Program...\n";
                    break;
                default:
                    std::cout << "You made an illegal choice.\n\n";
                    std::cout << "Trying to get out of standing?\n";
                    std::cout << "Choose again!";
                    break;
            }
        } while ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 4));

        /*============================Sitting Session================================*/
        // If 1 is chosen, start sitting session
        if (choice == 1)
        {
            // Introduce the user to Stumpy
            std::cout << "Ello! " << user_name << ", I am your friendly Sitting Adviser.\n";
            std::cout << "Please, call me Stumpy. I will manage your\n";
            std::cout << "sitting time. I will start out by recommending\n";
            std::cout << "you stand up from your chair every 15 minutes.\n";
            std::cout << "If you would like to change the time, you still\n";
            std::cout << "can do so. If you want to change the default,\n";
            std::cout << "just say so... Lets get started!\n\n";

            // Ask user if they want to change the sitting time
            std::cout << "Do you want to use the default sitting time of\n";
            std::cout << "15 minutes? Or would you like to change it?\n";
            // Show the options to user
            std::cout << "1 - I will use the default sitting time\n";
            std::cout << "2 - I would like to change it\n";
            std::cin >> choice;
            // If user choices the second option
            if (choice == 2)
            {
                std::cout << "Ok, what would you like to change the timer to?\n";
                std::cout << "I would not recommend over 30 minutes.\n";
                std::cout << "Please give Stumpy a time: \n";
                // Assign pointer to address of alarm_time
                Pointer = &alarm_time;
                // Get user input
                std::cin >> *Pointer;
                std::cout << "Ok! I will get you off your seat\n";
                std::cout << "every " << *Pointer << " minutes...\n";
            }
            // If user chooses first option
            else
            {
                std::cout << "Cool! I will get you off your seat\n";
                std::cout << "every " << alarm_time << " minutes...\n";
            }
            // Put the user in a while loop until they no longer want the time
            while (true)
            {
                std::cout << "Begin!\n";
                // Take the current time and add "alarm_time" to it. Store it in "tend".
                std::chrono::steady_clock::time_point tend =
                        std::chrono::steady_clock::now() + std::chrono::minutes(alarm_time);
                // Start timer that will end when "tend" time is meat.
                while (std::chrono::steady_clock::now() < tend) {
                    display_current_time_by_seconds();
                }
                // Alarm User
                std::cout << "\n\t\tSTAND UP! STUMPY COMMANDS IT!\t\t\n";
                // Add to how many times user stood up
                num_of_user_stands++;
                // Get current time
                time (&rawtime);
                // Put it in "timeinfo"
                timeinfo = localtime (&rawtime);
                // Turn the time into a string variable
                std::string stand_up_time = asctime(timeinfo);
                // Know put it on vector
                sitting_data.insert(sitting_data.begin(), stand_up_time);
                // Ask if user wants to continue
                std::cout << "Press 'r' when you are ready again, or\n";
                std::cout << "press 's' to stop and go to main menu.\n";
                std::cin >> input;
                if (input == 'r')
                    continue;
                else
                    break;
            }
        }

        /*=======================Change User Information=======================*/
        else if (choice == 2)
        {
            std::cout << "Ello, Stumpy here.\n";
            // Enter loop
            while (true)
            {
                // Show user their current data
                std::cout << "Here is your current user information: \n";
                for (int i = 0; i < user_info.size(); ++i)
                {
                    std::cout << ref_to_vector(user_info, i) << std::endl;
                }
                // Ask user what they want to change
                std::cout << "What would you like to change?\n";
                std::cout << "1 - Name\n";
                std::cout << "2 - Sex\n";
                std::cout << "3 - Age\n";
                std::cout << "4 - Nothing needs to be changed\n";
                // Wait for user input
                std::cin >> choice;

                if (choice == 1)
                {
                    // Get name
                    std::cout << "Please enter a name: \n";
                    std::cin >> new_input;
                    // Create a reference variable and assign it to first spot in vector
                    std::string& rStr = ref_to_vector(user_info, 0);
                    // Use reference variable to change element in vector
                    rStr = new_input;
                    std::cout << "I have saved your data.\n\n";
                }
                else if (choice == 2)
                {
                    // Get name
                    std::cout << "Please enter your sex: \n";
                    std::cin >> new_input;
                    // Create a reference variable and assign it to second spot in vector
                    std::string& rStr = ref_to_vector(user_info, 1);
                    // Use reference variable to change element in vector
                    rStr = new_input;
                    std::cout << "I have saved your data.\n\n";
                }
                else if (choice == 3)
                {
                    // Get name
                    std::cout << "Please enter your age: \n";
                    std::cin >> new_input;
                    // Create a reference variable and assign it to third spot in vector
                    std::string& rStr = ref_to_vector(user_info, 2);
                    // Use reference variable to change element in vector
                    rStr = new_input;
                    std::cout << "I have saved your data.\n\n";
                }
                else if (choice == 4)
                {
                    // Go back to menu
                    break;
                }
                else
                {
                    std::cout << "Invalid input, try again.\n";
                }
            }
        }

        /*========================About and Help=============================*/
        else if (choice == 3)
        {
            std::cout << "Ello, Stumpy here again.\n";
            // Enter loop
            while (true)
            {
                // Show options on what to do
                std::cout << "Here I can help you with any\n";
                std::cout << "questions you may have. Also,\n";
                std::cout << "you can see your saved sitting\n";
                std::cout << "data here.\n";
                // Ask user what they want to change
                std::cout << "What would you like to do?\n";
                std::cout << "1 - See Your Results\n";
                std::cout << "2 - About Program\n";
                std::cout << "3 - View User Info\n";
                std::cout << "4 - Back to Main Menu\n";
                std::cin >> choice;

                if (choice == 1)
                {
                    // Bring out Stumpy!
                    std::cout << "Ello! I see you want to see your results?\n";
                    std::cout << "I got two pieces of data for you.\n";
                    // Put user in while loop
                    while(true)
                    {
                        std::cout << "\n\tWhat would you like to see?\t\n";
                        std::cout << "1 - See at what times you stood up.\n";
                        std::cout << "2 - See how many times you stood up.\n";
                        std::cout << "3 - Go back to menu.\n";

                        // Wait for input
                        std::cin >> choice;
                        if (choice == 1)
                        {
                            std::cout << "All the time you stood up: \n";
                            // Display list of times by reference
                            for (int i = 0; i < sitting_data.size(); ++i)
                            {
                                std::cout << ref_to_vector(sitting_data, i) << std::endl;
                            }
                        }
                        else if (choice == 2)
                        {
                            std::cout << "You have stood up a total of: \n";
                            // Assign pointer to address of num_of_user_stands
                            Pointer = &num_of_user_stands;
                            std::cout << *Pointer << ", times. Good job!";
                        }
                        else if (choice == 3)
                        {
                            // Back to main menu
                            break;
                        }
                        else
                        {
                            std::cout << "invalidInput, Stumpy says NO!";
                        }
                    }


                }
                else if (choice == 2)
                {
                    // Call about program function
                    about_program();
                }
                else if (choice == 3)
                {
                    std::cout << "This is your current user info\n";
                    std::cout << "If you would like to change, \n";
                    std::cout << "please do so at the Main Menu\n";
                    // Show user data
                    for (int i = 0; i < user_info.size(); ++i)
                    {
                        std::cout << ref_to_vector(user_info, i) << std::endl;
                    }
                }
                else if (choice == 4)
                {
                    // Go back to main menu
                    break;
                }
                else
                {
                    std::cout << "Invalid input, try again.\n";
                }
            }
        }
        /*==========================Quit Program============================*/
        else if (choice == 4)
        {
            std::cout << "See you next time!\n";
            break;
        }
        else
        {
            // Incase anything unexpected happens
            std::cout << "ERROR: please restart program...";
        }
    }
    return 0;
}


