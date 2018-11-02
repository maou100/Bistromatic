/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtraction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 00:05:06 by feedme            #+#    #+#             */
/*   Updated: 2018/10/19 00:05:10 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bistro.h"

t_nbrs    *subtraction(char *nb1, char *nb2)
{
    int     i;
    int     j;
    int     k;
    t_nbrs  *new;
    int     remaind;
    int     base;
    int     index;
    char    booly;

    POUR SOUSTRACTION: FLIP LES NOMBRES POUR QUE NB1 > NB2 PUIS METTRE BOOL PR LE NEG A LA FIN

    booly = 1;
    ft_anybase_strcmp(nb1, nb2) >= 0 ? booly = 0 : ft_str_swap(&nb1, &nb2);
    if (!(i = ft_strlen(nb1)) || !(j = ft_strlen(nb2)) || (remaind = 0) || !(base = ft_strlen(g_base)))
        ft_exit_msg("syntax error\n");
    k = i;
    new = new_t_nbr();
    if (!(new->nbr = ft_strnew(k)))
        exit(0);
    while (--j >= 0)
    {
        --i;
        index = ft_get_index(ft_char_to_index(nb1[i], g_base) - ft_char_to_index(nb2[j], g_base) - remaind, base);
        new->nbr[--k] = g_base[index];
        remaind = ft_char_to_index(nb1[i], g_base) < ft_char_to_index(nb2[i], g_base) ? 1 : 0;
    }
    while (--i >= 0)
    {
        index = ft_get_index(ft_char_to_index(nb1[i], g_base) - 0 - remaind, base);
        new->nbr[--k] = g_base[index];
        remaind = 0;
    }
	new->nbr = set_begg_properly(new->nbr);
    if (booly)
        new->sign = 1;
    return (new);
}

t_nbrs  *sub_main(t_nbrs *nb1, t_nbrs *nb2)
{
    if (nb1->sign && nb2->sign)
        return (subtraction(nb2, nb1));
    else if (!nb1->sign && !nb2->sign)
        return (subtraction(nb1, nb2));
    else if (nb1->sign)
        return (primordial_oper_aka_add(nb1, nb2, 1));
    else
        return (primordial_oper_aka_add(nb1, nb2, 0));
}