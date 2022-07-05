
#include "Book.h"
#include <iostream>

int Book::count = 0; // initializing the of the static variable count

Book::Book() //Empty constructor to intialize each variable
{
    title = " ";
    isbn = " ";
    category = " ";
    averageRating = 0;
    count++;
    NumOfRating++;
    id = count;
}
Book::Book(string title, string isbn, string category) // setting the intialization values of the parameterized constructor
{
    this->title = title;
    this->isbn = isbn;
    this->category = category;
    count++;
    id = count;
}
Book::Book(const Book& book) // copy constructor
{
    this->title = book.title;
    this->isbn = book.isbn;
    this->category = book.category;
    count++;
    id = count;
}

void Book::setTitle(string t) // setting the value of title
{
    title = t;
}
string Book::getTitle() // getting the value of the title
{
    return title;
}
void Book::setISBN(string i) // setting the value the isbn
{
    isbn = i;
}
string Book::getISBN() // getting the value of the isbn
{
    return isbn;
}
void Book::setId(int id) // setting a new id
{
    if (id > this->id)
        this->id = id;
    else
    {
        cout << "ID must be greater than the previous ID (Enter greater one)" << endl;
        cin >> id;
        setId(id);
    }
}
int Book::getId() //getting the value of the id
{
    return id;
}
double Book::getAverage()
{
    return averageRating;
}
void Book::setCategory(string c) // setting a new category
{
    category = c;
}
string Book::getCategory() // getting the new category
{
    return category;
}
void Book::setAuthor(const User user)
{
    author = user;
}
User Book::getAuthor()
{
    return author;
}
void Book::setRateBook(double rating) // taking a new rating and calculating the new average
{
    NumOfRating++;
    sumRating += rating;
    averageRating = sumRating / NumOfRating;
}
double Book::getRating() {
    return averageRating;
}
bool Book::operator ==(const Book& book) //overloading == operator
{
    if (title == book.title && isbn == book.isbn && category == book.category && id == book.id)
        return true;
    else
        return false;
}
istream& operator >>(istream& is, Book& book) // overloading >> operator
{
    cout << "Enter the book information in this order \nTitle ISBN Category (Space separeted) \n";
    is >> book.title >> book.isbn >> book.category;
    cout << endl;
    return is;

}
ostream& operator<<(ostream& os, const Book& book) // overloading << operator
{
    cout << "==================== Book " << book.id << " info ========================" << endl;
    os << "Title: " << book.title << "| ISBN: " << book.isbn << "| Id: " << book.id << "| Category: " << book.category << "| Avg Rating: " << book.averageRating << endl;
    cout << "========================================================== \n\n";
    return os;
}



