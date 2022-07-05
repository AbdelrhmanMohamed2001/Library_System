#include "BookList.h"
#include "User.h"
#include "BOOK.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

BookList::BookList() {
    booksCount = 0;
}

BookList::BookList(int cap) {
    booksCount = 0;
    capacity = cap;
    books = new Book[cap];
}

BookList::BookList(const BookList& another) {
    booksCount = another.booksCount;
    capacity = another.capacity;
    books = new Book[capacity];
    for (int i = 0; i < booksCount; i++)
        books[i] = another.books[i];
}

void BookList::setCapacity(int cap) {
    capacity = cap;
    books = new Book[capacity];
}

void BookList::addBook(Book& book) {
    cin >> book;
    books[booksCount] = book;
    books[booksCount].setId(booksCount + 1);
    booksCount++;
}

Book& BookList::searchBook(string name) {
    for (int i = 0; i < booksCount; i++) {
        if (books[i].getTitle() == name)
            return books[i];
    }
    cout << "There is no BOOK with NAME = " << name << endl;
    exit(0);
}

Book& BookList::searchBook(int id) {
    for (int i = 0; i < booksCount; i++) {
        if (books[i].getId() == id)
            return books[i];
    }
    cout << "There is no BOOK with ID = " << id << endl;
    exit(0);
}

void BookList::deleteBook(int id) {
    bool isID = false;
    for (int i = 0; i < booksCount; i++) {
        if (books[i].getId() == id) {
            isID = true;
            for (int j = i; j < booksCount - 1; j++) {
                Book booksSwap = books[j];
                books[j] = books[j + 1];
                books[j + 1] = booksSwap;
            }
        }
    }
    if (isID)
        booksCount--;
    else {
        cout << "There is no BOOK with ID = " << id << endl;
        exit(0);
    }
}

Book& BookList::getTheHighestRatedBook() {
    int max = books[0].getAverage(), j = 0;
    for (int i = 0; i < booksCount - 1; i++) {
        if (books[i].getAverage() > books[i + 1].getAverage() && books[i].getAverage() > max) {
            max = books[i].getAverage();
            j = i;
        }
    }
    return books[j];
}

Book* BookList::getBooksforUser(User user) {
    int counter = 0;
    for (int i = 0; i < booksCount; i++) {
        if (books[i].getAuthor() == user)
            counter++;
    }
    if (counter != 0) {
        Book* userBooks = new Book[counter];
        for (int i = 0; i < counter; i++) {
            if (books[i].getAuthor() == user)
                userBooks[i] = books[i];
        }
        return userBooks;
    }
    else {
        cout << "There's no books for user" << user.getName() << endl;
        exit(0);
    }

}
Book& BookList::operator[](int pos) {
    if (pos<0 || pos>booksCount) {
        cout << "Wrong index" << endl;
        exit(0);
    }
    else
        return books[pos - 1];
}

ostream& operator<<(ostream& output, BookList& bookList) {
    for (int i = 0; i < bookList.booksCount; i++) {
//        *output << bookList.books[i];
    }
    return output;
}

BookList::~BookList()
{
    delete[] books;
}

