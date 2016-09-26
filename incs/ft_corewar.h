#ifndef FT_COREWAR_H
# define FT_COREWAR_H
/*
 *	Header lié à corewar
 */

/* LIB STANDAR */
# include <fcntl.h>
# include <dirent.h>
# include <limits.h>
# include "libft.h"
# include "mlx.h"
/* LIB COREWAR/MLX */
# include "op.h"
# include "ft_conf.h"
# include "ft_conf_obj.h"
# include "ft_terminal_log.h"
# include "ft_struct_mlx.h"
# include "ft_struct_vm.h"
# include "ft_struct_args.h"
# include "ft_struct_data.h"
# include "ft_mlx.h"

/* FICHIER FT_EXIT.C */
int		exit1(int err, t_data *d, char *msg);
int		exit2(int err, t_data *d, char *del, char *msg);
void	exitascii(t_data *d, int err, char *msg);

/* FICHIER FT_FREE.C */
void	free_data(t_data *d);

/* FICHIER FT_COREWAR.C */
t_data	*data(void);

/* FICHIER FT_VM_INIT.C */
void	vm_init(t_data *d, t_dvm *v);

/* FICHIER FT_VM.C */
void	vm(t_dvm *v, int cperloop);

/* FICHIER FT_VM_PROCESSUS.C */
void	proc_new(t_data *d, t_proc *new, int player, int i);
int		proc_kill(t_data *d, t_proc *target, t_proc *procdie);

/* FICHIER FT_GAMELOOP.C */
int		gameloop(t_dvm *v);

/* Tools */
// caca
// ca c'est kdo bsx :)
int		ft_little_to_big(int little);
char	*ft_read_code_champ(int size);
void	ft_recup_files(t_dvm *vm, t_dargs *args, char **argv, int argc);
void	ft_recup_headers(t_dvm *vm, t_dargs *args);
void	ft_recup_code(t_dvm *vm, t_dargs *args);
void	ft_fill_arene(t_dvm *vm);
#endif
