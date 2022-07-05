#include "User.h"

int User::count = 0; //static count variabel to count how many objects are there

User::User() // Empty constructor to intialize the attributes
{
	name_ = "";
	age_ = 0;
	email_ = "";
	password_ = "";
	count++;
	id_ = count;
}

User::User(string name, int age, string email, string password) // Parametarized constructor to set the values the attributes
{
	name_ = name;
	age_ = age;
	email_ = email;
	password_ = password;
	count++;
	id_ = count;
}

User::User(User& user) // copy constructor to make a copy of the object
{
	this->name_ = user.name_;
	this->age_ = user.age_;
	this->email_ = user.email_;
	this->id_ = user.id_;
	count++;
	id_ = user.id_;
}

User::~User()//Destructor
{
	count--;
	id_--;
}

bool User::operator == (const User& user) // Operator Overloading to compare to objects
{
	if (this->name_ == user.name_ && this->email_ == user.email_ && this->age_ == user.age_ && this->id_ == user.id_)
		return true;
	else
		return false;
}

void User::setName(string name)
{
	name_ = name;
}

string User::getName()
{
	return name_;
}

void User::setPassword(string password)
{
	password_ = password;
}

string User::getPassword()
{
	return password_;
}

void User::setEmail(string email)
{
	email_ = email;
}

string User::getEmail()
{
	return email_;
}

void User::setAge(int age)
{
	age_ = age;
}

int User::getAge()
{
	return age_;
}

void User::setId(int id)
{
		this->id_ = id;
}

int User::getId()
{
	return id_;
}

istream& operator >> (istream& is, User& u)
{
	string ageString; // this variable to recieve a string age in then i can convert this age later into integer

	cout << "Enter the User information in this order \nName Age Email Password (Space separated)\n";
	is >> u.name_ >> ageString >> u.email_ >> u.password_;
	cout << endl;
//	u.age_ = stoi(ageString); //Converting String Age into integer
	return is;
}

ostream& operator<<(ostream& os, const User& u)
{
	cout << "========== User " << u.id_ << " Info ===========" << endl;
	os << "Name: " << u.name_ << " |Age: " << u.name_ << " Id: " << u.id_ << " Email: " << u.email_ << endl;
	cout << "============================================= \n\n";
	return os;
}
