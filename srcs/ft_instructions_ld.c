#include "ft_corewar.h"

void	ft_instructions_ld(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	int registre;
	(void)vm;
	(void)inst;
	(void)proc;
	if (ft_check_value_args(proc->args, &inst))
	{
		registre = proc->args[1].value;
		if (ft_get_args(proc))
		{
			*(proc->ireg + registre - 1) = proc->args[0].value % IDX_MOD;
				proc->carry = !proc->carry;
			/*
			if ((*(proc->ireg + registre - 1) = proc->args[0].value) > 0)
				proc->carry = !proc->carry;
				*/
			/*
			else
				proc->carry = 0;
				*/
		}
		else
			proc->carry = 0;
	}
	else
		proc->carry = 0;
	proc->pc = proc->pc_turfu / 2;
//	ft_printf("instruction %s\n", inst.name);
}