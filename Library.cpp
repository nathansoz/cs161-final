#include "Library.h"
#include "Book.h"
#include <iomanip>
#include <iostream>
#include <string>

Library::Library()
{
    holdings.reserve(100);
    members.reserve(100);
    currentDate = 0;
}

void Library::addBook()
{
    std::string idCode;
    std::string title;
    std::string author;

    std::cin.ignore(1000, '\n');

    std::cout << "Please enter the idCode of the book: ";
    std::getline(std::cin, idCode);
    std::cout << "Please enter the title of the book: ";
    std::getline(std::cin, title);
    std::cout << "Please enter the author of the book: ";
    std::getline(std::cin, author);

    if(GetBook(idCode) != NULL)
    {
        std::cout << "That book ID already exists!" << std::endl;
        std::cout << "Returning to menu." << std::endl << std::endl;
        return;
    }

    Book tmpBook(idCode, title, author);
    holdings.push_back(tmpBook);

}

void Library::addMember()
{
    std::cin.ignore(1000, '\n');
    std::string idNumber;
    std::string name;

    std::cout << "Please enter the ID number of the patron: ";
    std::getline(std::cin, idNumber);
    std::cout << "Please enter the name of the patron: ";
    std::getline(std::cin, name);

    if(GetPatron(idNumber) != NULL)
    {
        std::cout << "That patron ID already exists!" << std::endl;
        std::cout << "Returning to menu." << std::endl << std::endl;
        return;
    }

    Patron tmpPatron(idNumber, name);

    members.push_back(tmpPatron);
}

void Library::checkOutBook(std::string patronID, std::string bookID)
{
    Book* book = GetBook(bookID);
    Patron* patron = GetPatron(patronID);

    if(book == NULL || patron == NULL)
    {
        return;
    }

    if(book->getLocation() == CHECKED_OUT)
    {
        std::cout << "This book is already checked out.";
    }
    else if(book->getLocation() == ON_HOLD)
    {
        if(book->getRequestedBy()->getIdNum() == patron->getIdNum())
        {
            book->setLocation(CHECKED_OUT);
            book->setCheckedOutBy(GetPatron(patronID));
            book->setDateCheckedOut(currentDate);
            book->setRequestedBy(NULL);
            patron->addBook(book);
        }
        else
        {
            std::cout << "This book is on hold and can only be checked out to requestee." << std::endl <<std::endl;
        }
    }
    else
    {
        book->setLocation(CHECKED_OUT);
        book->setCheckedOutBy(patron);
        book->setDateCheckedOut(currentDate);
        patron->addBook(book);
    }
}

int Library::GetCurrentDate()
{
    return currentDate;
}

Patron* Library::GetPatron(std::string idNum)
{
    for(int i = 0; i < members.size(); i++)
    {
        if(members.at(i).getIdNum() == idNum)
        {
            return &members.at(i);
        }
    }

    return NULL;
}

Book* Library::GetBook(std::string idNum)
{
    for(int i = 0; i < holdings.size(); i++)
    {
        if(holdings.at(i).getIdCode() == idNum)
        {
            return &holdings.at(i);
        }
    }

    return NULL;
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
    Book* book = GetBook(bookID);
    Patron* patron = GetPatron(patronID);

    if(book == NULL || patron == NULL)
    {
        return;
    }

    if(book->getRequestedBy() == NULL)
    {
        book->setRequestedBy(patron);
        if(book->getLocation() == ON_SHELF)
        {
            book->setLocation(ON_HOLD);
        }
    }
    else
    {
        std::cout << "This book is already requested!";
    }
}

void Library::returnBook(std::string bookID)
{
    Book* book = GetBook(bookID);
    
    if(book == NULL)
    {
        return;
    }
    if(book->getLocation() == ON_SHELF)
    {
        std::cout << "This book is already on the shelf.";
    }
    else
    {
        Patron* patron = book->getCheckedOutBy();

        if(book->getRequestedBy() == NULL)
        {
            book->setLocation(ON_SHELF);
            book->setCheckedOutBy(NULL);
            book->setDateCheckedOut(-1);
            patron->removeBook(book);
        }
        else
        {
            book->setLocation(ON_HOLD);
            book->setCheckedOutBy(NULL);
            book->setDateCheckedOut(-1);
            patron->removeBook(book);
        }
    }
}

void Library::viewBookInfo(std::string bookID)
{
    Book* book = GetBook(bookID);

    if(book == NULL)
    {
        std::cout << "No such holding exists." << std::endl;
    }
    else
    {
        std::cout << std::endl << "ID: " << book->getIdCode() << std::endl;
        std::cout << "Title: " << book->getTitle() << std::endl;
        std::cout << "Author: " << book->getAuthor() << std::endl;

        if(book->getLocation() == ON_SHELF)
        {
            std::cout << "Location: ON SHELF" << std::endl;
        }
        else if(book->getLocation() == ON_HOLD)
        {
            std::cout << "Location: ON HOLD" << std::endl;
            std::cout << "Requested By: " << book->getRequestedBy()->getName() << std::endl;
            std::cout << "Requested By ID: " << book->getRequestedBy()->getIdNum() << std::endl;
        }
        else
        {
            std::cout << "Location: CHECKED OUT" << std::endl;
            std::cout << "Checked out by: " << book->getCheckedOutBy()->getName() << std::endl;
            std::cout << "Checked out by ID: " << book->getCheckedOutBy()->getIdNum() << std::endl;
            std::cout << "Due date: " << book->getDateCheckedOut() + 21 << std::endl;

            if(book->getRequestedBy() != NULL)
            {
                std::cout << "This book is also requested by patron: " << book->getRequestedBy()->getIdNum()
                        << std::endl;

                std::cout << "It should be put on the hold shelf when checked back in." << std::endl;
            }
        }
    }
}

void Library::viewPatronInfo(std::string patronID)
{
    Patron* patron = GetPatron(patronID);

    if(patron == NULL)
    {
        std::cout << std::endl << "That patron does not exist!" << std::endl;
    }
    else
    {
        std::cout << std::endl << "Patron ID: " << patron->getIdNum() << std::endl;
        std::cout << "Name: " << patron->getName() << std::endl;
        std::cout << "Fines: $" << std::setprecision(2) << std::fixed << patron->getFineAmount() << std::endl;

        if(patron->getCheckedOutBooks().size() == 0)
        {

        }
    }
}



