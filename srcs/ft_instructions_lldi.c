#include "ft_corewar.h"

void	ft_instructions_lldi(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	int registre;
	int address;
	t_argument argument;

	(void)vm;
	(void)inst;
	(void)proc;
	registre = 0;
	if (proc->ok)
		return ;
		if (ft_check_value_args(proc->args, &inst, vm, proc))
	{
		registre = proc->args[2].value;
		if (ft_get_args(proc))
		{

			address = (proc->args[0].value % IDX_MOD +
					proc->args[1].value % IDX_MOD) * 2;
			ft_fill_args_dir(&argument, vm, address);
			*(proc->ireg + registre) = argument.value;
		}
	}
	proc->pc = proc->pc_turfu / 2;
	l2(13, "INSTRUCTION", "instruction lldi", proc->id);
//	ft_printf("instruction %s\n", inst.name);

}
