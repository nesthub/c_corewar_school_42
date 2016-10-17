#ifndef FT_STRUCT_DATA_H
# define FT_STRUCT_DATA_H

typedef struct			s_drez
{
	char				mode;
}						t_drez;

typedef struct			s_data
{
	struct s_dmlx		mlx;
	struct s_drez		rez;
	struct s_dvm		vm;
	struct s_dargs		args[5];
}						t_data;

#endif
