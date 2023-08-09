#ifndef FIXED_HPP
#define	FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
	private:
		int fixedPoint;
		static const int mantissa = 8;
	public:
		Fixed();
		Fixed(int value);
		Fixed(const float value);
		Fixed(const Fixed &cpy);
		Fixed &operator = (const Fixed &copyFixed);
		~Fixed();
		int getRawBits( void ) const;
    	void setRawBits( int const raw );
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator << (std::ostream &output, const Fixed &fixed);

#endif
