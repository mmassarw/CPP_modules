#include "Contact.hpp"

Contact::Contact(){
}

Contact::~Contact(){
}

std::string	Contact::input(std::string prompt){
	std::string	string;
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
	return (string);
}

void	Contact::initialize(){
	this->first = this->input("First Name: ");
	this->last = this->input("Last Name: ");
	this->nick = this->input("Nickname: ");
	this->digits = this->input("Phone Number: ");
	this->secret = this->input("Darkest Secret: ");
}

void	Contact::display(std::string index){
    std::cout << "------------------------" << std::endl;
    std::cout << "---->> CONTACT #" << index << " <<----" << std::endl;
    std::cout << "First Name:\t" << this->first << std::endl;
    std::cout << "Last Name:\t" << this->last << std::endl;
    std::cout << "Nickname:\t" << this->nick << std::endl;
    std::cout << "Phone Number:\t" << this->digits << std::endl;
    std::cout << "Deepest Secret:\t" << this->secret << std::endl;
    std::cout << "------------------------" << std::endl;
}

void	Contact::table(std::string index){
	std::cout << "|" << std::setw(10) << index << std::flush;
	if (this->first.length() > 10)
		std::cout << "|" << std::setw(9) << this->first.substr(0,9) << "." << std::flush;
	else
		std::cout << "|" << std::setw(10) << this->first << std::flush;
	if (this->last.length() > 10)
		std::cout << "|" << std::setw(9) << this->last.substr(0,9) << "." << std::flush;
	else
		std::cout << "|" << std::setw(10) << this->last << std::flush;
	if (this->nick.length() > 10)
		std::cout << "|" << std::setw(9) << this->nick.substr(0,9) << "." << std::flush;
	else
		std::cout << "|" << std::setw(10) << this->nick << std::flush;
	std::cout << "|" << std::endl;
}