#include "Patron.h"
Patron::Patron() {}

Patron::Patron(std::string idn, std::string n)
{
    idNum = idn;
    name = n;
    fineAmount = 0.00;
    checkedOutBooks.reserve(100);
}

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

void Patron::removeBook(Book *b)
{
    for(int i = 0; i < checkedOutBooks.size(); i++)
    {
        if(b == checkedOutBooks.at(i))
        {
            checkedOutBooks.erase(checkedOutBooks.begin() + i);
            break;
        }
        else
        {
            continue;
        }
    }
}