#pragma once
#include <iostream>
#include <cmath>

class Fixed{
	public:
		Fixed();
		Fixed(int const);
		Fixed(float const);
		Fixed(Fixed const&);
		~Fixed();

		Fixed&					operator=(Fixed const&);
		Fixed					operator+( Fixed const& copy ) const;
		Fixed					operator-( Fixed const& copy ) const;
		Fixed					operator*( Fixed const& copy ) const;
		Fixed					operator/( Fixed const& copy ) const;
		bool					operator>( Fixed const& copy ) const;
		bool					operator<( Fixed const& copy ) const;
		bool					operator>=( Fixed const& copy ) const;
		bool					operator<=( Fixed const& copy ) const;
		bool					operator==( Fixed const& copy ) const;
		bool					operator!=( Fixed const& copy ) const;
		Fixed					operator++( void );
		Fixed					operator++( int num );
		Fixed					operator--( void );
		Fixed					operator--( int num );

		int						getRawBits() const;
		void					setRawBits(int const);
		float					toFloat() const;
		int						toInt() const;
		static Fixed&			min(Fixed& a, Fixed& b);
		static const Fixed&		min(const Fixed& a, const Fixed& b);
		static Fixed&			max(Fixed& a, Fixed& b);
		static const Fixed&		max(const Fixed& a, const Fixed& b);
	
	private:
		int					_value;
		static const int	_fraction = 8;
};

std::ostream &operator<<(std::ostream&, Fixed const&);