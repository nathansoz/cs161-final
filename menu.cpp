#include "Book.h"
#include "Library.h"
#include "Patron.h"
#include <iostream>
#include <string>
#include <stdlib.h>

int main()
{
    Library library;

    std::cout << "Welcome to the library system!" << std::endl;
    std::cout << "Please choose an option below." << std::endl << std::endl;

    while(true)
    {
        int userSelection = -1;

        std::cout << "Menu:" << std::endl;

        std::cout << "1) View patron info" << std::endl;
        std::cout << "2) View book info" << std::endl;
        std::cout << "3) Check out book" << std::endl;
        std::cout << "4) Return book" << std::endl;
        std::cout << "5) Place book on hold" << std::endl;
        std::cout << "6) Pay fine" << std::endl;
        std::cout << "7) Add a book" << std::endl;
        std::cout << "8) Add a patron" << std::endl;
        std::cout << "9) Increment day" << std::endl;
        std::cout << "10) Exit" << std::endl;

        std::cout << std::endl << "Selection: ";
        std::cin >> userSelection;

        switch (userSelection)
        {
            case 1:
            {
                std::string tmpID;
                std::cout << "Enter patron id: ";
                std::cin.ignore(1000, '\n');
                getline(std::cin, tmpID);
                library.viewPatronInfo(tmpID);
                break;
            }
            case 2:
            {
                std::string tmpID;
                std::cout << "Enter book id: ";
                std::cin.ignore(1000, '\n');
                getline(std::cin, tmpID);
                library.viewBookInfo(tmpID);
                break;
            }
            case 3:
            {
                std::string tmpPatronID;
                std::string tmpBookID;
                std::cout << "Enter patron id: ";
                std::cin.ignore(1000, '\n');
                getline(std::cin, tmpPatronID);
                std::cout << "Enter book id: ";
                getline(std::cin, tmpBookID);
                library.checkOutBook(tmpPatronID, tmpBookID);
                break;
            }
            case 4:
            {
                std::string tmpID;
                std::cout << "Enter book id: ";
                std::cin.ignore(1000, '\n');
                getline(std::cin, tmpID);
                library.returnBook(tmpID);
                break;
            }
            case 5:
            {
                std::string tmpPatronID;
                std::string tmpBookID;
                std::cout << "Enter patron id: ";
                std::cin.ignore(1000, '\n');
                getline(std::cin, tmpPatronID);
                std::cout << "Enter book id: ";
                getline(std::cin, tmpBookID);
                library.requestBook(tmpPatronID, tmpBookID);
                break;
            }
            case 6:
                break;
            case 7:
                library.addBook();
                break;
            case 8:
                library.addMember();
                break;
            case 9:
                library.incrementCurrentDate();
                std::cout << "The date is now: " << library.GetCurrentDate() << std::endl << std::endl;
                break;
            case 10:
                exit(0);
                break;
            default:
                std::cout << "Invalid selection!" << std::endl;
                break;
        }
    }
}
