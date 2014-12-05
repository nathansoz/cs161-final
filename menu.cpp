#include "Book.h"
#include "Library.h"
#include "Patron.h"
#include <iostream>
#include <string>

int main()
{
    Library newLib;

    newLib.addBook();
    newLib.addMember();

    std::cout << "Requesting first time.";
    newLib.requestBook("123", "123");
    std::cout << "Requesting second time.";
    newLib.requestBook("123", "123");

    return 0;
}