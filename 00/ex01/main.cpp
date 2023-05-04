#include "PhoneBook.hpp"

int	main(){
	PhoneBook	phoneBook;
	std::string	prompt;

	std::cout << "<<==========WELCOME TO PhoneBook==========>>" << std::endl;
	std::cout << "type ADD to save a new contact" << std::endl;
	std::cout << "type SEARCH to display a specific contact" << std::endl;
	std::cout << "type EXIT to EXIT" << std::endl;
	while (1)
	{
		prompt = Contact::input("Enter your prompt: ");
		if (std::cin.eof())
			return (1);
		else if (prompt == "ADD")
			phoneBook.addContact();
		else if (prompt == "SEARCH")
			phoneBook.searchContacts();
		else if (prompt == "EXIT"){
			std::cout << "Exiting" << std::endl;
			return (0);
		} else
			 std::cout << "Incorrect input" << std::endl;
	}
	return (0);
}