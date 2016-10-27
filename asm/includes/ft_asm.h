#ifndef FT_ASM_H
# define FT_ASM_H

#include "ft_struct_asm.h"
# define NBR_INST 17

/*
** Recuperation des infos du (des) fichiers
*/
int			ft_open_file(char **argv);
int			ft_get_size_file(int fd);
char		*ft_get_line(int fd, t_lexer *lexer);


/*
** Instructions
*/

void		ft_init_instructions(t_instructions *inst);
void		ft_init_instructions_name(t_instructions *inst);
void		ft_init_instructions_nbr_args(t_instructions *inst);
void		ft_init_instructions_types_arg_zero(t_instructions *inst);
void		ft_init_instructions_types_arg_un(t_instructions *inst);
void		ft_init_instructions_types_arg_deux(t_instructions *inst);
/*
** Lexer
*/
t_token		*ft_new_token(t_lexer *lexer);
void		ft_init_lexer(t_lexer *lexer);
int			ft_lexer(t_lexer *lexer);
void		ft_get_value(t_lexer *lexer, t_token *token, int size);


void		ft_free_tokens(t_token *token);
void		ft_lexer_error(t_lexer *lexer, int erreur);
void		ft_free_elem_pile(t_pile_tree *tree, t_parser *parser);

/*
**	Display
*/
void		ft_display_tokenisation(t_token *token);
void		ft_display_type_token(int token);
void		ft_display_parse_tree(t_parse_tree *tree);

/*
**			Tokenisation
*/
int			ft_lexer_command_name(t_lexer *lexer, t_token *token);
int			ft_lexer_command_comment(t_lexer *lexer, t_token *token);
int			ft_lexer_comment(t_lexer *lexer, t_token *token);
int			ft_lexer_string(t_lexer *lexer, t_token *token);
int			ft_lexer_whitespace(t_lexer *lexer, t_token *token);
int			ft_lexer_separator(t_lexer *lexer, t_token *token);
int			ft_lexer_label(t_lexer *lexer, t_token *token);
int			ft_lexer_direct(t_lexer *lexer, t_token *token);
int			ft_lexer_instruction(t_lexer *lexer, t_token *token);
int			ft_lexer_indirect(t_lexer *lexer, t_token *token);
int			ft_lexer_indirect_label(t_lexer *lexer, t_token *token);
int			ft_lexer_direct_label(t_lexer *lexer, t_token *token);
int			ft_lexer_register(t_lexer *lexer, t_token *token);
int			ft_lexer_endline(t_lexer *lexer, t_token *token);
int			ft_lexer_end(t_lexer *lexer, t_token *token);

/*
**	Parser
*/

int			ft_parser(t_token *token, t_parser *parser);
void		ft_init_parser(t_parser *parser);

int			ft_parser_shift(t_parser *parser);
int			ft_parser_reduce(t_parser *parser);
int			ft_parser_accept(t_parser *parser);

void		ft_free_pointeur_tab_fils(t_parse_tree *tree);

/*
**			rules
*/
int			ft_rule_name(t_parser *parser, t_pile_tree *pile);
int			ft_rule_ccomment(t_parser *parser, t_pile_tree *pile);
int			ft_rule_endline(t_parser *parser, t_pile_tree *pile);
int			ft_rule_instruction(t_parser *parser, t_pile_tree *pile);
int			ft_rule_separator_char(t_parser *parser, t_pile_tree *pile);
int			ft_rule_argument(t_parser *parser, t_pile_tree *tree);
int			ft_rule_end(t_parser *parser, t_pile_tree *tree);

/*
**			accept rules
*/

int			ft_accept_header(t_parser *parser, t_pile_tree *pile);
int			ft_accept_label(t_parser *parser, t_pile_tree *pile);
int			ft_accept_name(t_parser *parser, t_pile_tree *pile);
int			ft_accept_comment(t_parser *parser, t_pile_tree *pile);
int			ft_accept_argument(t_parser *parser, t_pile_tree *pile);
int			ft_accept_instruction(t_parser *parser, t_pile_tree *pile);
int			ft_accept_separator_char(t_parser *parser, t_pile_tree *tree);
int			ft_accept_end(t_parser *parser, t_pile_tree *tree);
int			ft_accept_code_header(t_parser *parser, t_pile_tree *tree);
/*
**			checks
*/

int			ft_check_name_instructions(char *instructions, t_instructions *inst);
void		ft_add_leaf(t_parse_tree *tree, t_parse_tree *leaf);
void		ft_add_tree_shift(t_parser *parser);
void		ft_add_parent_tree(t_pile_tree *tree, t_parser *parser);
int			ft_verif_instruction(t_pile_tree *pile, t_pile_tree *next,
		t_instructions *inst);

/*
**			shifts
*/

int			ft_shift_no_focus(t_parser *parser);
int			ft_shift_whitespaces(t_parser *parser);
int			ft_shift_command_name(t_parser *parser);
int			ft_shift_string(t_parser *parser);
int			ft_shift_endline(t_parser *parser);
int			ft_shift_command_comment(t_parser *parser);
int			ft_shift_label(t_parser *parser);
int			ft_shift_instruction(t_parser *parser);
int			ft_shift_register(t_parser *parser);
int			ft_shift_separator_char(t_parser *pasrer);
int			ft_shift_direct_label(t_parser *pasrer);
int			ft_shift_direct(t_parser *pasrer);
int			ft_shift_indirect(t_parser *parser);
int			ft_shift_end(t_parser *parser);
/*
** Parse tree
*/

void		ft_add_node(t_parse_tree *tree, t_parse_tree *leaf);
t_parse_tree *ft_create_leaf(t_token *token);

/*
**	compilation
*/

void			ft_init_compilation(t_compile *compile);
int				ft_compilation(t_parse_tree *tree, t_parser *parser);
unsigned char	ft_set_oc_p(unsigned int id, t_parse_tree *inst);
int				ft_compile(t_parse_tree *tree,t_compile *compile, unsigned char *code);

unsigned char	*ft_compile_name(t_parse_tree *tree, unsigned char *code,
		t_compile *compile);
unsigned char	*ft_compile_comment(t_parse_tree *tree, unsigned char *code,
		t_compile *compile);
unsigned char	*ft_compile_string(t_parse_tree *tree, unsigned char *code,
		t_compile *compile);
unsigned char	*ft_compile_label(t_parse_tree *tree, unsigned char *code,
		t_compile *compile);
unsigned char	*ft_compile_register(t_parse_tree *tree, unsigned char *code,
		t_compile *compile);
unsigned char	*ft_compile_indirect(t_parse_tree *tree, unsigned char *code,
		t_compile *compile);
unsigned char	*ft_compile_instruction(t_parse_tree *tree, unsigned char *code,
		t_compile *compile);
unsigned char	*ft_compile_indirect_label(t_parse_tree *tree, unsigned char *code,
		t_compile *compile);
unsigned char	*ft_compile_direct(t_parse_tree *tree, unsigned char *code,
		t_compile *compile);
unsigned char	*ft_compile_direct_label(t_parse_tree *tree, unsigned char *code,
		t_compile *compile);
#endif