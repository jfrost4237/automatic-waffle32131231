#include "functions.h"



void Start() {
    
        std::cout << "enter file name: ";
        std::cin >> file;
        std::cout << "\n";
    

    int choice = 0;
    std::cout << "1 = Enter grades\n2 = Print table of grades\n3 = Exit\n\nenter choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1: start_grading();
        break;
    case 2: {
        std::cout << "\nWhich subject would you like to enter?\n";
        std::cin >> subject;
       
        std::transform(subject.begin(), subject.end(), subject.begin(), [](unsigned char c) { return std::tolower(c); });

        print_vector(subject);
        break;
    }
    case 3: abort; break;
        
    }

   
}


    
