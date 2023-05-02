#pragma once
#include <iostream>
#include <cmath>

class Fixed{
	public:
		Fixed();
		Fixed(int const);
		Fixed(float const);
		Fixed(Fixed const&);
		Fixed&operator=(Fixed const&);
		~Fixed();
		int		getRawBits() const;
		void	setRawBits(int const);
		float	toFloat() const;
		int		toInt() const;
	
	private:
		int					_value;
		static const int	_fraction = 8;
};

std::ostream &operator<<(std::ostream&, Fixed const&);