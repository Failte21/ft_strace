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

# include "sysent.h"

# define O_RDI  14
# define O_RSI  13
# define O_RDX  12
# define O_RCX  11
# define O_R8   9
# define O_R9   8

/*
** error
*/
void    *null_error(const char *s);
void    *null_perror(const char *s);
int     int_error(const char *s);
int     int_perror(const char *s);

#endif
