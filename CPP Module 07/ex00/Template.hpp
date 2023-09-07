#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

template <typename T1>

void swap(T1& a, T1&b)
{
	T1 temp;

	temp = a;
	a = b;
	b = temp;
};

template <typename T2>

T2 min(T2& a, T2& b)
{
	if(a > b)
		return b;
	else if (b > a)
		return a;
	else
		return b;
}

template <typename T3>

T3 max(T3& a, T3& b)
{
	if(a > b)
		return a;
	else if (b > a)
		return b;
	else
		return b;
};

#endif