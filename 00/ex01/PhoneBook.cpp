#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	this->contactCount = 0;
	this->fillIndex = 0;
}

PhoneBook::~PhoneBook(){
}

bool PhoneBook::startingDigit(const std::string& str) {
    size_t i = 0;
    while (i < str.size() && std::isspace(str[i]))
        i++;
    if (i < str.size() && (str[i] == '+' || str[i] == '-'))
        i++;
    return (i < str.size() && std::isdigit(str[i]));
}

int	PhoneBook::input(std::string prompt){
	std::string	string;
	int			number;
	bool		state = false;
	do
	{
		std::cout << prompt << std::flush;
		std::getline(std::cin, string);
		if (std::cin.good() && !string.empty())
			state = true;
		else
			std::cout << "Prompt error" << std::endl;
	} while (!state && !std::cin.eof());
	if (std::cin.eof()){
		std::cout << "EOF entered, exiting program" << std::endl;
	}
	if (string.length() > 1)
		return (-1);
	number = std::atoi(string.c_str());
	return (number);
}

void PhoneBook::addContact(){
	if (this->fillIndex > 7)
		this->fillIndex = 0;
	this->contacts[fillIndex].initialize();
	if (this->contactCount < 8)
		this->contactCount++;
	this->fillIndex++;
}

void PhoneBook::searchContacts(){
	std::stringstream itoa;
	if (this->contactCount == 0) {
		std::cout << "The phone book is empty." << std::endl;
		return;
	}
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < this->contactCount; i++) {
		itoa.str("");
		itoa << (i + 1);
		this->contacts[i].table(itoa.str());
	}
	int index;
	index = PhoneBook::input("Please enter the index of the contact you want to display: ");
	if (index < this->contactCount && index > 0){
		itoa.str("");
		itoa << index;
		this->contacts[(index - 1)].display(itoa.str());
	}
	else
		std::cout << "Invalid index." << std::endl;
}