#include <string>
#include <iostream>

class	Harl{
	public:
		Harl();
		~Harl();

		void	complain(std::string);
	
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};