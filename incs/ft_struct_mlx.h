#ifndef FT_STRUCT_MLX_H
# define FT_STRUCT_MLX_H
/*
 *	Header des données lié à mlx
 */

/* ENUM PERMETANT AU PROGRAMME DE SAVOIR LA SCENE QUI EST EN COURS */
enum scene {
	INTRO,
	VM_INIT,
	VM
};

/* IDENTIFIANT DES ZONE CLICABLE, GRACE A LUI ON RETROUVE LES COORD
 * DE CHAQUE ZONE */
enum coord {
	MENU
};

/* STRUCT DE GESTION DES COORDONNé POUR LES MOUSEOVER
 * - le tableau arreé contien 2 fois le couple de coordoné x,y
 * - [2-3] pour le coin supérieur gauche [4-5] supérieur droit
 * - Lors d'un clic ces coordonnées servent à vérifier si la zone match
 *   avec l'élément associé */
typedef struct		s_mo
{
	int				area[4];
}					t_mo;

/* STRUCT CONTENANT LES INFO DUNE IMAGE, PROPRE A MINILIBX UNIQUEMENT
 * - consulté le man mlx pour les détails de chaque variable */
typedef struct		s_img
{
	void			*img;
	char			*str;
	int				bpp;
	int				sl;
	int				end;
	int				i;
}					t_img;

/* STRUCT CONTENANT LE TABLEAU DE LIEN VERS TOUTES LES IMAGES DUNE SCENES
 * list[x] le x correspond au nombre maximum d'image que l'on pourra charger
 * par scene. si il est trop petit il faudra l'augmenter
 */
typedef struct		s_scene_img
{
	t_img			*l[SCENE_IMG_MAX];
}					t_scene_img;

/* STRUCT POUR INFORMER DE L'ETAT ENFONCé OU NON D'UNE TOUCHE
 * - si char <touche> = 0 -> touche laché, sinon elle est enfoncé
 * - mp_[x-y] pour la position d'un press, mo_[xy] pour mouseover */
typedef struct		s_input
{
	char			mleft;
	char			mright;
	char			left;
	char			right;
	char			up;
	char			down;
	char			shift;
	int				mo_x;
	int				mo_y;
	int				mr_x;
	int				mr_y;
}					t_input;

 /* DATA_MLX
  * Lien vers les structure du header ft_struct_mlx.h
  * contient également des donné statique ou int
  * - win et mlx sont necessaire pour la minilibx
  * - input contient l'état enfoncé ou relaché du clavier/souris
  * - loop et loopstop permette de controler le rafraichissment d'ecran
  * - scene indique la scene courante
  * - img_isload[x] est à 0 si les image de cette scene ne sont pas chargé
  * - scene_img[x] contient toutes les images de chaque scene
  * 	La valeur x ci-dessus représente le nombre de scene maximum possible,
  * 	si on dépasse SCENE_MAX scene il faudra l'augmenter
  * - coord permet de cibler les information des element clickable
  */
typedef struct			s_dmlx
{
	void				*mlx;
	void				*win;
	t_input				input;
	char				loop;
	char				loopstop;
	enum scene			scene;
	// nb. img_isload à 0 pour non, 1 pour chargé, 2 pour pas d'image
	// (cette information servira pour la fonction de free)
	char				img_isload[SCENE_MAX];
	t_scene_img			scene_img[SCENE_MAX];
	enum coord			coord;
}						t_dmlx;

#endif