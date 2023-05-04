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
	return (string);
}

void	Contact::initialize(){
	this->first = this->input("First Name: ");
	if (this->first.empty())
		return;
	this->last = this->input("Last Name: ");
	if (this->last.empty())
		return;
	this->nick = this->input("Nickname: ");
	if (this->nick.empty())
		return;
	this->digits = this->input("Phone Number: ");
	if (this->digits.empty())
		return;
	this->secret = this->input("Darkest Secret: ");
	if (this->secret.empty())
		return;
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