#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();
		void	addContact();
		void	displayContacts();
		void	searchContacts();

	private:
		Contact contacts[8];
		int		contactCount;
		int		fillIndex;

		int		input(std::string);
		bool	startingDigit(const std::string&);
};

#endif
