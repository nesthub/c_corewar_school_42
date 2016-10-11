#include "ft_corewar.h"

#include <stdio.h>

void	ft_instructions_st(t_dvm *vm, t_instructions inst, t_proc *proc)
{
	int registre;
	int registre1;
	int save;
	int convert;

	(void)vm;
	(void)inst;
	(void)proc;
	convert = 0;
	l2(13, "INSTRUCTION", "instruction st", proc->id);

	if (ft_check_value_args(proc->args, &inst, vm, proc))
	{
		registre = proc->args[1].value;
		registre1 = proc->args[0].value;
		save = proc->args[1].value;
		proc->args[1].value = (proc->args[1].value )% IDX_MOD;
		convert = ft_convert_pc(proc->args[1].value);

		if (ft_get_args(proc))
		{
			if (proc->args[1].type == REG_CODE)
			{
				if (vm->options.operations)
				ft_printf("P%5d | st r%d r%d\n", proc->id + 1, registre1, registre);
				*(proc->ireg + registre - 1) = proc->args[0].value;
			}
			else
			{
				if (vm->options.operations)
				ft_printf("P%5d | st r%d %d\n", proc->id + 1, registre1, save);
				ft_put_registre(vm->arene, (unsigned int)proc->args[0].value,
						(proc->pc + convert ) * 2);
				ft_put_color_size(vm->color, ARENE_CODE_COLOR_P4,
						proc->pc + convert , 4);
			}
		}
	}
	proc->pc = (proc->pc_turfu / 2) ;

	l2(13, "INSTRUCTION", "instruction st", proc->id);
	//	ft_printf("instruction %s\n", inst.name);
}
