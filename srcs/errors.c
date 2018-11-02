/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 14:32:08 by feedme            #+#    #+#             */
/*   Updated: 2018/10/16 22:35:05 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bistro.h"
#include <stdio.h>

char    *get_input(void)
{
    char    *input;
    int     ret;
    char    *xtra_line;

    ret = 0;
    if ((ret = get_next_line(0, &input)) == -1)
        exit(0);
    else if (!ret) // syntax error for gnl_ret= 0 (empty line...or...rather no actual line?)
        ft_exit_msg("syntax error\n");
    if (get_next_line(0, &xtra_line) == 1) // that's if there's another line of operation
    {
        free(xtra_line);
        ft_exit_msg("syntax error\n");
    }
    return (input);
}

// void    check_av2(char *str)
// {
//     int     i;

//     i = -1;
//     while (str[++i])// BIIIIIIIIIIIIIIEN TROP LENT, VERIFIER AU FUR ET A MESURE
//     {
//         if (!ft_isdigit(str[i]))
//         {
//             if (str[i] == '+' && !i)
//                 continue ;
//             exit(0);
//         }
//     }
// }

int    check_opers(char *str)
{
    int     i;

    i = 0;
    while (IS_OPER(str[i]))
    {
        if (str[i] == '*' || str[i] == '/' || str[i] == '%')
            ft_exit_msg("syntax error\n");
        i++;
    }
    if (!str[i])
        ft_exit_msg("syntax error\n");
    return (1);
}

char    *rm_xtra_oper(char *str, int i, int k)
{
    char    *input;
    int     len;
    int     j;
    char    neg;

    len = ft_strlen(str);
    if (!(input = ft_strnew(len)))
        exit(0);
    while (str[i])
    {
        neg = 0;
        j = 0;
        if (IS_OPER(str[i]) && IS_OPER(str[i + 1]) && check_opers(str + i))
        {
            while (IS_OPER(str[j + i]))
            {
                if (str[i + j] == '-')
                    neg = neg ? 0 : 1;
                else
                    neg = neg ? 1 : 0;
                j++;
            }
            input[k] = neg ? '-' : '+';
            i += j;
        }
        else
        {
            input[k] = str[i];
            i++;
        }
        k++;
    }
   free(str);
    return (input);
}

if ((IS_OPER(input[i]) || input[i] = ')') && // CHECKER: operand et parentheses respectives pour debut et fin (a part + et - au debut) et que ya pas 2 operands a la suite (a par si c un -)
        {

        }

char     *check_errors(char **av)
{
	int     i;
	char    *input;
	int     parenthesis_c;

    parenthesis_c = 0;
    i = -1;
    input = get_input();
    //check_av1(av[1]); // check les doublons ds la char *base
    //check_av2(av[2]); // ridiculously overchecking function
	if ((int)ft_strlen(input) != ft_atoi(av[2])) // Question: input plus long que 2,147,483,647 caracteres.....?
	    ft_exit_msg("syntax error\n");
    input = rm_xtra_oper(input, 0, 0)
    while (input[++i])
    {       
        if (parenthesis_c < 0 || (!IS_OPER_AND_PAR(input[i]) && !ft_strchr(g_base, input[i])) ||
        (input[i] == '(' && i > 0 && !IS_OPER(input[i - 1]) && input[i - 1] == ')') ||
        (input[i] == ')' && !IS_OPER(input[i + 1]) && input[i + 1] && input[i + 1] == '('))
            ft_exit_msg("syntax error\n");
        if (input[i] == '(' || input[i] == ')')
            input[i] == '(' ? parenthesis_c++ : parenthesis_c--;
    }
    if (parenthesis_c)
        ft_exit_msg("syntax error\n");
    return (input);
}


// TODO: fct pour checker les doublons ds la char *base