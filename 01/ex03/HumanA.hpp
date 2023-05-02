#include "Weapon.hpp"

class	HumanA{
	public:
		HumanA(std::string, Weapon&);
		~HumanA();

		void	attack();

	private:
		HumanA();
		std::string	name;
		Weapon		*weapon;
};