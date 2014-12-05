#include "Library.h"
#include "Book.h"
#include <iostream>
#include <string>

void Library::addBook()
{
    std::string idCode;
    std::string title;
    std::string author;

    //std::cin.ignore(1000, '\n');

    std::cout << "Please enter the idCode of the book: ";
    std::getline(std::cin, idCode);
    std::cout << "Please enter the title of the book: ";
    std::getline(std::cin, title);
    std::cout << "Please enter the author of the book: ";
    std::getline(std::cin, author);

    Book tmpBook(idCode, title, author);

    holdings.push_back(tmpBook);

}

void Library::addMember()
{
    std::string idNumber;
    std::string name;

    std::cout << "Please enter the ID number of the patron: ";
    std::getline(std::cin, idNumber);
    std::cout << "Please enter the name of the patron: ";
    std::getline(std::cin, name);

    Patron tmpPatron(idNumber, name);

    members.push_back(tmpPatron);
}

void Library::checkOutBook(std::string patronID, std::string bookID)
{

}

void Library::incrementCurrentDate()
{
    currentDate++;
}

void Library::payFine(std::string patronID, double payment)
{
    for(int i = 0; i < members.size(); i++)
    {
        if(members.at(i).getIdNum() == patronID)
        {
            members.at(i).amendFine(-(payment));
            break;
        }
    }
}

void Library::requestBook(std::string patronID, std::string bookID)
{
    for(int i = 0; i < members.size(); i++)
    {
        if(members.at(i).getIdNum() == patronID)
        {
            for(int i = 0; i < holdings.size(); i++)
            {
                if(holdings.at(i).getIdCode() == bookID)
                {
                    if(holdings.at(i).getRequestedBy() == NULL)
                    {
                        holdings.at(i).setRequestedBy(&(members.at(i)));
                    }
                    else
                    {
                        std::cout << "This book is already requested!";
                    }
                }
            }
        }
    }
}

void Library::returnBook(std::string bookID)
{
    for(int i = 0; i < holdings.size(); i++)
    {
        if(holdings.at(i).getIdCode() == bookID)
        {
            if(holdings.at(i).getLocation() == ON_SHELF)
            {
                std::cout << "This book is already on the shelf.";
            }
            else
            {
                if(holdings.at(i).getRequestedBy() == NULL)
                {
                    holdings.at(i).setLocation(ON_SHELF);
                    holdings.at(i).setCheckedOutBy(NULL);
                    holdings.at(i).setDateCheckedOut(-1);
                }
                else
                {
                    holdings.at(i).setLocation(ON_HOLD);
                    holdings.at(i).setCheckedOutBy(NULL);
                    holdings.at(i).setDateCheckedOut(-1);
                }
            }
        }
    }
}

