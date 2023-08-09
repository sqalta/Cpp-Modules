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

int Fixed::getRawBits() const
{
	std::cout << "getRawBits Called" << std::endl;
	return (this->fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPoint = raw;
}

bool Fixed::operator < (const Fixed &r) const
{
	return (this->fixedPoint < r.fixedPoint);
}

bool Fixed::operator > (const Fixed &r) const
{
	return (this->fixedPoint > r.fixedPoint);
}

bool Fixed::operator <= (const Fixed &r) const
{
	return (this->fixedPoint <= r.fixedPoint);
}

bool Fixed::operator >= (const Fixed &r) const
{
	return (this->fixedPoint >= r.fixedPoint);
}

bool Fixed::operator == (const Fixed &r) const
{
	return (this->fixedPoint == r.fixedPoint);
}

bool Fixed::operator != (const Fixed &r) const
{
	return (this->fixedPoint != r.fixedPoint);
}

float Fixed::operator + (const Fixed &r)
{
	return (this->toFloat() + r.toFloat());
}

float Fixed::operator - (const Fixed &r)
{
	return (this->toFloat() - r.toFloat());
}

float Fixed::operator / (const Fixed &r)
{
	return (this->toFloat() / r.toFloat());
}

float Fixed::operator * (const Fixed &r)
{
	return (this->toFloat() * r.toFloat());
}

Fixed &Fixed::operator++()
{
	this->fixedPoint++;
	return (*this);
}

Fixed &Fixed::operator--()
{
	this->fixedPoint--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed x;
	x = *this;
	++*this;
	return (x);
}

Fixed Fixed::operator--(int)
{
	Fixed x = *this;
	--*this;
	return (x);
}

Fixed &Fixed::min(Fixed &r1, Fixed &r2)
{
	return ((r1.fixedPoint < r2.fixedPoint) ? r1 : r2);
}

const Fixed &Fixed::min(const Fixed &r1, const Fixed &r2)
{
	return ((r1.fixedPoint < r2.fixedPoint) ? r1 : r2);
}

Fixed &Fixed::max(Fixed &r1, Fixed &r2)
{
	return ((r1.fixedPoint > r2.fixedPoint) ? r1 : r2);
}

const Fixed &Fixed::max(const Fixed &r1, const Fixed &r2)
{
	return ((r1.fixedPoint > r2.fixedPoint) ? r1 : r2);
}

std::ostream &operator << (std::ostream &output, const Fixed &fixed)
{
	output << fixed.toFloat();
	return (output);
}