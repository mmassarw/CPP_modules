#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <iomanip>
#include <cstdlib>
# include <string>
#include <sstream>

class Contact {
	public:
		Contact();
		~Contact();
		void				initialize();
		void				display(std::string);
		void				table(std::string);
		static std::string	input(std::string);

	private:
		std::string	first;
		std::string last;
		std::string	nick;
		std::string	digits;
		std::string secret;

};

#endif