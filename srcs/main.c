# include "../inc/ft_strace.h"

int	run_subprogram(const char *subprogram_name)
{
	char *const args[] = {NULL};

	if (execv(subprogram_name, args) == -1)
		return (int_perror("Unable to execute subprogram"));
	return (0);
}

int lookup(pid_t pid)
{
	int						status;
	struct user_regs_struct	regs;

	ptrace(PTRACE_SEIZE, pid, NULL, NULL);
	ptrace(PTRACE_INTERRUPT, pid, NULL, NULL);
	wait(&status);
	while(1) {
		ptrace(PTRACE_GETREGS, pid, NULL, &regs);
		printf("(debug) regs.rip: %llx\n", regs.rip);
		ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			return (0);
	}
	return (0);
}

int main(int ac, char **av)
{
	pid_t					child;

	if (ac != 2)
	{
		dprintf(2, "usage: ./ft_strace program\n");
		return (1);
	}
	child = fork();
	if (child == 0)
	{
		if (run_subprogram(av[2]) == -1)
			return (1);
	} else {
		if (lookup(child) == -1)
			return (1);
	}
	return (0);
}
