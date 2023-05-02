#include <iostream>

class Fixed{
	public:
		Fixed();
		Fixed(Fixed const&);
		Fixed&operator=(Fixed const&);
		~Fixed();
		int	getRawBits() const;
		void setRawBits(int const);
	
	private:
		int					_value;
		static const int	_fraction = 8;
};