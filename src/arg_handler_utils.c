#include "../inc/fractol.h"

static bool	is_digit(int c)
{
	return (c >= 48 && c <= 57);
}

static bool	is_space(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (false);
}

static bool	get_fraction(char *str, double *nb)
{
	double div;

	div = 0.1;
	if (*str == '.')
		str++;
	while (*str && is_digit(*str))
	{
		*nb = *nb + ((*str - '0') * div);
		div *= 0.1;
		str++;
	}
	while (is_space(*str))
		str++;
	if (*str)
		return (false);
	return (true);
}

bool	get_julia_cnst(char *str, double *nb)
{
	int		sign;

	*nb = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && is_digit(*str) && *str != '.')
	{
		*nb = (*nb * 10.0) + (*str - '0');
		str++;
	}
	if (!get_fraction(str, nb))
		return (false);
	*nb *= sign;
	return (true);
}
