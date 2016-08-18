#include "ft_corewar.h"

void	*mlx_xpmtostruct(t_dmlx *m, t_img *img, char *file)
{
	if (!(img->img) && LOG_XTOI == 1)
		l(8, "GET XPM IMG", file);
	if (!(img->img)
	&& !(img->img = mlx_xpm_file_to_image(m->mlx, file, &img->sl, &img->end)))
		exit1(1, data(), "Cant load xpm file");
	if (!(img->str) && LOG_XTOI == 1)
		l(8, "GET XPM STR", file);
	if (!(img->str))
		img->str = mlx_get_data_addr(img->img, &img->bpp, &img->sl, &img->end);
	return (img->img);
}