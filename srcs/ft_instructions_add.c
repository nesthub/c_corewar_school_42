#include "ft_corewar.h"

void	ft_instructions_add(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	int registre;
	int registre1;
	int registre2;

	(void)vm;
	(void)inst;
	(void)proc;

		if (ft_check_value_args(proc->args, &inst, vm, proc))
		{
			registre = proc->args[2].value;
			registre1 = proc->args[0].value;
			registre2 = proc->args[1].value;
			if (ft_get_args(proc))
			{
				if (vm->options.operations)
					ft_printf("P%5d | add r%d r%d r%d\n", proc->id + 1, registre1, registre2, registre);
				proc->args[2].value = registre;
				if ((*(proc->ireg + registre - 1)
							= proc->args[0].value + proc->args[1].value))
					proc->carry = 0;
				else
					proc->carry = 1;
			}
		}
	proc->pc = (proc->pc_turfu / 2) % MEM_SIZE;
	//	proc->pc = proc->pc_turfu / 2;
}
