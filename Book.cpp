#include "Book.h"

//Constructor for a book. Sets the read-only properties

Book::Book(std::string idc, std::string t, std::string a)
{
    idCode = idc;
    title = t;
    author = a;
    location = ON_SHELF;
    requestedBy = NULL;
    checkedOutBy = NULL;

}

//All of the getters for properties
std::string Book::getAuthor()
{
    return author;
}

Patron* Book::getCheckedOutBy()
{
    return checkedOutBy;
}

int Book::getDateCheckedOut()
{
    return dateCheckedOut;
}

std::string Book::getIdCode()
{
    return idCode;
}

Locale Book::getLocation()
{
    return location;
}

Patron* Book::getRequestedBy()
{
    return requestedBy;
}

std::string Book::getTitle()
{
    return title;
}

//Setters for non read-only properties
void Book::setCheckedOutBy(Patron *p)
{
    checkedOutBy = p;
}

void Book::setDateCheckedOut(int d)
{
    dateCheckedOut = d;
}

void Book::setLocation(Locale lo)
{
    location = lo;
}

void Book::setRequestedBy(Patron *p)
{
    requestedBy = p;
}