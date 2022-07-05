#include <iostream>
#include <string>
#include "BookList.h"
#include "UserList.h"
using namespace std;
void mainMenu() {
    cout << "MAIN MENU" << endl;
    cout << "1- Books Menu" << endl;
    cout << "2- Users Menu" << endl;
    cout << "3- Exit" << endl;
}
void bookMenu() {
    cout << "BOOK MENU" << endl;
    cout << "1- Create a book and add it to the list" << endl;
    cout << "2- Search for a book" << endl;
    cout << "3- Display all books (with rating)" << endl;
    cout << "4- Get the highest rated book" << endl;
    cout << "5- Get all book for a user" << endl;
    cout << "6- Current the current Book List to a new Book List and switch to it" << endl;
    cout << "7- Back to the main menu" << endl;
}
void userMenu() {
    cout << "USER MENU" << endl;
    cout << "1- Create a user and add it to the list" << endl;
    cout << "2- Search for a user" << endl;
    cout << "3- Display all users" << endl;
    cout << "4- Back to the main menu" << endl;
}

int main() {
    int userChoice, numUsers = 0, numBooks = 0;
    UserList myUsersList;
    BookList myBookList;
    while (true) {
        mainMenu();
        cin >> userChoice;

        // UsersMenu
        if (userChoice == 2) {
            cout << "How many users will be added?";
            cin >> numUsers;
            myUsersList.setCapacity(numUsers);

            while (true) {
                User user;
                userMenu();

                cin >> userChoice;
                if (userChoice == 1) {
                    myUsersList.addUser(user);
                }
                else if (userChoice == 2) {
                    cout << "SEARCH FOT A USER" << endl;
                    cout << "1- Search by name" << endl;
                    cout << "2- Search by id" << endl;
                    cout << "3- Return for users menu" << endl;

                    cin >> userChoice;
                    if (userChoice == 1 || userChoice == 2) {
                        User user;
                        if (userChoice == 1) {
                            string name;
                            cout << "Enter name: ";
                            cin >> name;
                            user = myUsersList.searchUser(name);
                            cout << user << endl;
                        }
                        else {
                            int id;
                            cout << "Enter ID: ";
                            cin >> id;
                            user = myUsersList.searchUser(id);
                            cout << user << endl;
                        }

                        cout << "1- Delete user" << endl;
                        cout << "2- Return to Users Menu" << endl;
                        cin >> userChoice;
                        if (userChoice == 1)
                            myUsersList.deleteUser(user.getId());
                    }

                }
                else if (userChoice == 3) {
                    cout << myUsersList << endl;
                }
                else
                    break;
            }
        }

        //Books Menu
        else if (userChoice == 1) {
            cout << "How many books will be added?";
            cin >> numBooks;
            myBookList.setCapacity(numBooks);
            int counter = 0;

            while (true) {
                Book book;
                bookMenu();
                cin >> userChoice;
                if (userChoice == 1) {
                    myBookList.addBook(book);
                    counter++;
                    cout << "1- Assign Author" << endl;
                    cout << "2- Continue" << endl;
                    cin >> userChoice;
                    if (userChoice == 1) {
                        cout << "Enter Author (user) id: " << endl;
                        int iD;
                        cin >> iD;
                        myBookList[counter].setAuthor(myUsersList.searchUser(iD));
                    }
                    else if (userChoice == 2) {
                        cout << "SEARCH FOR A BOOK" << endl;
                        cout << "1- Search by name" << endl;
                        cout << "2- Search by id" << endl;
                        cout << "3- Return to Books Menu" << endl;
                        cin >> userChoice;
                        if (userChoice == 1 || userChoice == 2) {
                            string name;
                            int id;
                            bool entry = false;
                            if (userChoice == 1) {
                                cout << "Enter name: " << endl;
                                cin >> name;
                                cout << myBookList.searchBook(name) << endl;
                            }
                            else {
                                cout << "Enter ID: " << endl;
                                cin >> id;
                                cout << myBookList.searchBook(id);
                                entry = true;
                            }
                            while (true) {
                                cout << "1- Update Author" << endl;
                                cout << "2- Update Name" << endl;
                                cout << "3- Update Category" << endl;
                                cout << "4- Delete Book" << endl;
                                cout << "5- Rate Book" << endl;
                                cout << "6- Update Author" << endl;
                                cout << "7- Get back to books menu" << endl;
                                cin >> userChoice;
                                if (userChoice == 1) {
                                    cout << "Enter Author (user) ID: " << endl;
                                    int i;
                                    cin >> i;
                                    if (entry)
                                        myBookList.searchBook(id).setAuthor(myUsersList.searchUser(i));
                                    else
                                        myBookList.searchBook(name).setAuthor(myUsersList.searchUser(i));
                                }
                                else if (userChoice == 2) {
                                    cout << "Enter new Name" << endl;
                                    string n;
                                    cin >> n;
                                    if (entry)
                                        myBookList.searchBook(id).setTitle(n);
                                    else
                                        myBookList.searchBook(name).setTitle(n);
                                }
                                else if (userChoice == 3) {
                                    cout << "Enter new Category" << endl;
                                    string c;
                                    cin >> c;
                                    if (entry)
                                        myBookList.searchBook(id).setCategory(c);
                                    else
                                        myBookList.searchBook(name).setCategory(c);
                                }
                                else if (userChoice == 4) {
                                    int i = myBookList.searchBook(name).getId();
                                    myBookList.deleteBook(i);
                                }
                                else if (userChoice == 5) {
                                    cout << "Enter Rating Value" << endl;
                                    double rate;
                                    cin >> rate;
                                    if (entry)
                                        myBookList.searchBook(name).setRateBook(rate);
                                    else
                                        myBookList.searchBook(id).setRateBook(rate);
                                }
                                else
                                    break;
                            }
                        }
                    }

                }
                else if (userChoice == 2) {
                    cout << myBookList << endl;
                }
                else if (userChoice == 3) {
                    cout << myBookList << endl;
                }
                else if (userChoice == 4) {
                    cout << myBookList.getTheHighestRatedBook() << endl;
                }
                else if (userChoice == 5) {
                    cout << "Enter User's ID: ";
                    int userid;
                    cin >> userid;
                    Book* tempBook = myBookList.getBooksforUser(myUsersList.searchUser(userid));
                    cout << endl;
                }
                else if (userChoice == 6) {
                    BookList myNewBookList;
                    myNewBookList = myBookList;
                    cout << "Copied current list (" << counter << " books) to a new list and switched to it" << endl;
                }
                else
                    break;
            }
        }
        // Exit
        else
            break;
    }
    return 0;
}

