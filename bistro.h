#ifndef BISTRO_H
# define BISTRO_H

# include "libft.h"

typedef struct      s_nbrs
{
    char            *nbr;
    char            sign;
    struct s_nbrs   *next;
}                   t_nbrs;

typedef struct              s_operators
{
    char                    oper;
    char                    weigh;
    struct s_operators      *next;
}                           t_opers;

char        *g_base;

char        *check_errors(char **av);
t_nbrs      *build_list(char *input);
int         get_index(char c, char *base_s);
int 		ft_char_to_index(char c, char *base);
int         ft_get_index(int shift, int base);
int         ft_get_remainder(int shift, int base);
char        *set_begg_properly(char *str);
int         ft_anybase_strcmp(char *nb1, char *nb2);
int         ft_anybase_strcmp(char *nb1, char *nb2);


# define IS_OPER_AND_PAR(x) (x == '+' || x == '-' || x == '*' || x == '/' || x == '%' || x == '(' || x == ')')
# define IS_OPER(x) (x == '+' || x == '-' || x == '*' || x == '/' || x == '%')

#endif
