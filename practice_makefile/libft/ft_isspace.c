#include "libft.h"

bool	ft_isspace(int c)
{
	char	ch;

	ch = (unsigned char) c;
	if (ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r' || ch == ' ')
		return (true);
	return (false);
}
