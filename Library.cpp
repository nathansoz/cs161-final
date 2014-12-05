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
}