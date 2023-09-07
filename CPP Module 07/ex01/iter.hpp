#ifndef	ITER_HPP
# define ITER_HPP

template <typename T1>

void iter(T1* s, int length, void (*function)(const T1&))
{
	for (int i = 0; i < length; i++)
		function(s[i]);
}

#endif