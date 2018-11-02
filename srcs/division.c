/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   division.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 15:18:08 by feedme            #+#    #+#             */
/*   Updated: 2018/10/19 15:18:38 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bistro.h"
    /\
   / |\
  /  | \                A AND B NEED TO BE > 0
 /   .   \              A AND B CANT HAVE EXTRA 0 (EX: 000233)
/________ \         


char    *get_sub_dividend(char *nb1, char *nb2)
{
    int     i;
    char    booly;

    booly = 0;
    i = -1;
   while (nb2[++i])
    {
        if (ft_char_to_index(nb1[i]) < ft_char_to_index(nb2[i]) && !nb1[i + 1] && !booly)
            return (ft_one_char_str(g_base[0]));
        else if (ft_char_to_index(nb1[i]) > ft_char_to_index(nb2[i]))
            booly = 1;
    }
    if (ft_char_to_index(nb1[i - 1]) < ft_char_to_index(nb2[i - 1]))
        return (ft_strsub(nb1, 0, i + 1));
    else
        return (ft_strsub(nb1, 0, i));
}

int     ft_div_by_1_digit(char c, char *str)
{
    return ((ft_char_to_index(str[0]) * ft_strlen(g_base) + ft_char_to_index(str[1])) / ft_char_to_index(c));
}

char    *do_sub_div(char *nb1_tmp, char *rest, char *nb2, char *c)
{
    int     index;
    char    *new;
    char    *tmp;
    char    *tmp2;

    index = ft_div_by_1_digit(nb2[0], (tmp = ft_strsub(nb1_tmp, 0, 2)));
    index++; // AU CAS OU
    free(tmp);
    while (ft_anybase_strcmp(rest, (tmp2 = multiplication((tmp = ft_one_char_str(g_base[index])), nb2)) < 0))
    {
        free(tmp);
        free(tmp2);
        index--;
    }
    *c = g_base[index];
    new = subtraction(rest, (tmp2 = multiplication((tmp = ft_one_char_str(*c)), nb2));
    free(rest);
    free(tmp);
    free(tmp2);
    return (new);
}

char    *past_dot_div(char *rest, char *nb2, char *c)
{
    int     i;
    char    *tmp;
    char    *tmp2;
    char    *new;

    i = 0;
    while (ft_anybase_strcmp((tmp = multiplication((tmp2 = ft_one_char_str(g_base[i])), nb2)), rest) < 0)
    {
        i++;
        free(tmp);
        free(tmp2);
    }
    free(tmp);
    free(tmp2);
    i--;
    *c = g_base[i];
    tmp = ft_one_char_str(*c);
    new = multiplication(tmp, nb2);
    free(tmp);
    return (new);
}

t_nbrs  *division(char *nb1, char *nb2, char res_sign)
{
    int     i;
    char    *rest;
    char    *tmp;
    t_nbrs  *new;
    char    digit;
    char    *tmp2;
    int     past_dot;

    if (ft_anybase_strcmp(nb1, nb2) < 0 || (ft_char_to_index(nb1[0], g_base) == 0))
        return(ft_one_char_str(g_base[0]));
    if (ft_char_to_index(nb2[0], g_base) == 0)
        ft_exit_msg("syntax error\n");
    new = new_t_nbr();
    if (!(new->nbr = ft_strnew(ft_strlen(nb1) + 40)))
        exit (0);
    past_dot = 0;
    i = -1;
    rest = ft_strdup(nb1);
    while (ft_anybase_strcmp(rest, nb2) >= 0)
    {
        tmp = get_sub_dividend(rest, nb2);
        free(rest);
        rest = do_sub_div(tmp, rest, nb2, &digit);
        free(tmp);
        new->nbr[++i] = digit;
    }
    if (rest[0] != g_base[0])
    {
        new->nbr[++i] = '.';
        while (rest[0] != g_base[0] && g_past_dot < 42)
        {
            tmp = ft_strjoin(rest, (tmp2 = ft_one_char_str(g_base[0])));
            free(rest);
            rest = tmp;
            free(tmp2);
            rest = past_dot_div(rest, nb2, &digit);// <---- a verifier
            new->nbr[++i] = digit;
            past_dot++;
        }
    }
    free(rest);
    new->nbr = set_begg_properly(new->nbr);
    if (res_sign)
        new->sign = 1;
    return (new);
}

t_nbrs  *div_main(t_nbrs *nb1, t_nbrs *nb2)
{
    if ((nb1->sign && nb2->sign) || (!nb1->sign && !nb2->sign))
        return (division(nb1, nb2, 0));
    else
        return (division(nb1, nb2, 1));
}










// i = 0;
// j = 0;
// while (nb1[i])
// {
//     if (ft_char_to_index(nb1[i]) < ft_char_to_index(nb2[j]) && !nb1[i + 1])
//         return (ft_one_char_str(g_base[0]));
//     else if (ft_char_to_index(nb1[i]) == ft_char_to_index(nb2[j]))
//     {

//     }
//     else
//     {

//     }

// char    *division(char *A, char *B)
// {
//         A ET B >= 0

//         IF (A == B)
//             CHAR* = '0'
//         ELSE

//         I = 1;
//         WHILE (ft_anybase_strval_cmp(MULTIPLICATION(A, FT_ITOA(I)), B) < 0)
//             I++;

//         I--;

//         RETURN (DIVISION = g_base[I]);

// REFLECHIR A UNE AUTRE SOLUTION:
// SI     A / 1 = A
// ALORS  A / 2 = ?
// 
// 


// POUR A / C

//                                                 FAIRE C * BASE JUSKA AVANT DE DEPASSER A
//                                                 PUIS FAIRE * 2 JUSKA AVANT DE DEPASEER A
// POUR 58379 / 52 = 1122


// 58379
// _____        1 * base^3 = 1000
// 52000

// 6379
// ____         1 * base^2 = 100
// 5200

// 1179
// ____         2 * base^1 = 20
// 1040

// 139
// ____            2 * base^0 = 2
// 104

// 35  <----RESTE



}