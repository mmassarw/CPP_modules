#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource();
		MateriaSource(std::string const& type);
		MateriaSource(MateriaSource const& copy);
		MateriaSource&operator=(MateriaSource const& rhs);
		~MateriaSource();

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const& type);
};

#endif