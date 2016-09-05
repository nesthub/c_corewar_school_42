/*
** INITIALISATION DE LA VM
*/
#include "ft_corewar.h"

void	vm_init_log(void)
{
	// log terminal des valeur par default
	l2(11, "VM_INIT", "Cycle to die", CYCLE_TO_DIE);
	l2(11, "VM_INIT", "Cycle delta", CYCLE_DELTA);
	l2(11, "VM_INIT", "Nbr live", NBR_LIVE);
	l2(11, "VM_INIT", "Max Checks", MAX_CHECKS);
	l2(11, "VM_INIT", "Cycle per loop", CYCLE_PER_LOOP);
}

void	vm_init(t_data *d, t_dvm *v, int i)
{
	ft_bzero(&d->vm, sizeof(t_dvm));
	d->procdie = (t_proc *)NULL;

	// Debug pour forcer 4 joueurs ->
	v->p[0].playing = 1; v->p[1].playing = 1; v->p[2].playing = 1; v->p[3].playing = 1;
	// param dump qui sera récupéré depuis argv par la suite
	v->dump = 0;

	// initialise les variable et les log
	v->ctodie = CYCLE_TO_DIE;
	v->cperloop = CYCLE_PER_LOOP;
	v->cperprint = CYCLE_PER_PRINT;
	vm_init_log();

	// Créer le premier proc de chaque player
	// i * (MEM_SIZE / 4) représente le début du premier processeur de ce joueur dans l'arene
	// i est sont numéro (0-3) et MEM_SIZE / 4 la taille max par champion
	// nb: c'est peut être pas le bon calcule, à vérifier avant merge
	while (--i > -1)
		if (v->p[i].playing && l2(11, "PLAYER", "true", i))
	 		proc_new(d, (t_proc *)NULL, i, i * (MEM_SIZE / 4));
		else if (!v->p[i].playing)
			l2(11, "PLAYER", "false", i);
	// Change la scene actuel pour afficher la vm
	d->mlx.scene = VM;


	// debug..force le live sur tout les joueur
	d->proc->live = 1; // 3
	(d->proc->n)->live = 1; // 2
	((d->proc->n)->n)->live = 1; // 1
	(((d->proc->n)->n)->n)->live = 1; // 0
	// v->ctodie = 300;
}
