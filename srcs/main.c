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
	unsigned long long		old_rip;
	struct_sysent   		g_sysent[] = {
		# include "../inc/syscallent.h"
	};

	old_rip = 0;
	ptrace(PTRACE_SEIZE, pid, NULL, NULL);
	ptrace(PTRACE_INTERRUPT, pid, NULL, NULL);
	wait(&status);
	while(1) {
		ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			return (0);
		ptrace(PTRACE_GETREGS, pid, NULL, &regs);
		if (old_rip != regs.rip)
		{
			old_rip = regs.rip;
			printf("%s(", g_sysent[regs.orig_rax].sys_name);
			for (unsigned int i = 0; i < g_sysent[regs.orig_rax].nargs; i++)
			{
				unsigned long long *u_regs = (unsigned long long *)(&regs);
				unsigned long long reg = u_regs[O_RDI - i];
				printf("0x%llx", reg);
				if (i + 1 < g_sysent[regs.orig_rax].nargs)
					printf(", ");
			}
			printf(")\n");
		}
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
		if (run_subprogram(av[1]) == -1)
			return (1);
	} else {
		if (lookup(child) == -1)
			return (1);
	}
	return (0);
}
