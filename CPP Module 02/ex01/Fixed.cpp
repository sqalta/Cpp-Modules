#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPoint = 0;
}

Fixed::Fixed(int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPoint = value << mantissa;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPoint = (int)roundf(value * (1 << mantissa));
}

Fixed::Fixed(const Fixed &cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed &Fixed::operator=(const Fixed &copyFixed)
{
	std::cout << "Assigment operator called" << std::endl;
	this->fixedPoint = copyFixed.fixedPoint;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return ((float)this->fixedPoint / (1 << mantissa));
}

int Fixed::toInt(void) const
{
	return (this->fixedPoint >> mantissa);
}

std::ostream &operator << (std::ostream &output, const Fixed &fixed)
{
	output << fixed.toFloat();
	return (output);
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits Called" << std::endl;
	return (this->fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPoint = raw;
}