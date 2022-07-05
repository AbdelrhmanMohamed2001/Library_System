#include "UserList.h"
#include "User.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

UserList::UserList()
{
    usersCount = 0;
    capacity = 0;
    users = NULL;
}

UserList::UserList(int cap) {
    usersCount = 0;
    capacity = cap;
    users = new User[capacity];
}

void UserList::addUser(User& user) {
    cin >> user;
    users[usersCount] = user;
    users[usersCount].setId(usersCount + 1);
    usersCount++;
}
void UserList::setCapacity(int cap) {
    capacity = cap;
    users = new User[capacity];
}

User& UserList::searchUser(string name) {
    for (int i = 0; i < usersCount; i++) {
        if (users[i].getName() == name)
            return users[i];
    }
    cout << "There's no USER with  NAME=" << name << endl;
    exit(0);
}

User& UserList::searchUser(int id) {
    for (int i = 0; i < usersCount; i++) {
        if (users[i].getId() == id)
            return users[i];
    }
    cout << "There's no USER with ID=" << id << endl;
    exit(0);
}

void UserList::deleteUser(int id) {
    for (int i = 0; i < usersCount; i++) {
        if (users[i].getId() == id) {
            for (int j = i; j < usersCount - 1; j++) {
                User userSwap = users[j];
                users[j] = users[j + 1];
                users[j + 1] = userSwap;
            }
            usersCount--;
        }
    }
    cout << "There's no USER with ID=" << id << endl;
    exit(0);
}
ostream& operator<<(ostream& output,const UserList& userlist) {
    for (int i = 0; i < userlist.usersCount; i++) {
        output << userlist.users[i] << endl;
    }
    return output;
}

UserList::~UserList()
{
    delete[] users;
}
