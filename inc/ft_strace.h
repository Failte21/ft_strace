#ifndef FT_STRACE_H
# define FT_STRACE_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/user.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/ptrace.h>

/*
** error
*/
void    *null_error(const char *s);
void    *null_perror(const char *s);
int     int_error(const char *s);
int     int_perror(const char *s);

#endif
