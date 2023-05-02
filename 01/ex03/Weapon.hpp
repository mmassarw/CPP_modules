#include <string>
#include <iostream>

class	Weapon{
	public:
		Weapon();
		Weapon(std::string);
		~Weapon();

		const std::string&	getType();
		void 				setType(std::string);

	private:
		std::string type;
};