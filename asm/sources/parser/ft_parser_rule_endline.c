#include "libft.h"
#include "ft_asm.h"

static int	ft_check_endline(t_pile_tree *pile, t_parse_tree *tree)
{
	if (tree->token->token == ENDLINE)
	{
		pile->value = FIN_LINE;
		return (1);
	}
	return (0);
}

int			ft_rule_endline(t_parser *parser, t_pile_tree *pile)
{
	if (ft_check_endline(pile, pile->tree))
	{
		parser->focus_pile = 0;
		return (ACCEPT);
	}
	return (0);
}
