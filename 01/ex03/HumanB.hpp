#include "HumanA.hpp"

class	HumanB{
	public:
		HumanB(std::string);
		~HumanB();

		void	attack();
		void	setWeapon(Weapon&);
	private:
		std::string	name;
		Weapon		*weapon;
};