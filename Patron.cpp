#include <iostream>
#include "Patron.h"
Patron::Patron() {}

Patron::Patron(std::string idn, std::string n)
{
    //Init default values and reserve memory for checkedOutBooks vector
    idNum = idn;
    name = n;
    fineAmount = 0.00;
    checkedOutBooks.reserve(100);
}

//Getters for Patron class

std::vector<Book*> Patron::getCheckedOutBooks()
{
    return checkedOutBooks;
}

double Patron::getFineAmount()
{
    return fineAmount;
}

std::string Patron::getIdNum()
{
    return idNum;
}

std::string Patron::getName()
{
    return name;
}

void Patron::addBook(Book *b)
{
    checkedOutBooks.push_back(b);
}

void Patron::amendFine(double amount)
{
    fineAmount += amount;
}

//Loops through the Patron's books and removes it from their holdings if found
//Else returns error message
void Patron::removeBook(Book *b)
{
    for(int i = 0; i < checkedOutBooks.size(); i++)
    {
        if(b == checkedOutBooks.at(i))
        {
            //If found, remove and exit the function
            checkedOutBooks.erase(checkedOutBooks.begin() + i);
            return;
        }
        else
        {
            continue;
        }
    }

    //Return the error message if we get to this point
    std::cout << std::endl << "That Patron does not have that book." << std::endl << std::endl;
}