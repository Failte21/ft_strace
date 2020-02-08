#include "../inc/ft_strace.h"

void	*null_error(const char *s)
{
	dprintf(2, "%s\n", s);
	return (NULL);
}

int		int_error(const char *s)
{
	dprintf(2, "%s\n", s);
	return (-1);
}

void	*null_perror(const char *s)
{
	perror(s);
	return (NULL);
}

int		int_perror(const char *s)
{
	perror(s);
	return (-1);
}
