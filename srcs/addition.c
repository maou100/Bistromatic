/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 16:01:40 by feedme            #+#    #+#             */
/*   Updated: 2018/10/18 17:52:23 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bistro.h"

t_nbrs	*primordial_oper_aka_add(char *nb1, char *nb2, char res_sign)
{
    int     i;
    int     j; // if nb1 and nb2 are of different size we need 2 iterators cuz parsing from end
    int     k; // saving i+1 length to not have to strlen again
    t_nbrs  *new;
    int     remaind;
    int     base;
    int     index;
    
    ft_strlen(nb1) > ft_strlen(nb2) ? 0 : ft_str_swap(&(nb1), &(nb2));
    if (!(i = ft_strlen(nb1)) || !(j = ft_strlen(nb2)) || (remaind = 0) || !(base = ft_strlen(g_base)))
        ft_exit_msg("syntax error\n");
    k = i + 1;
    new->nbr = new_t_nbr();
    if (!(new->nbr = ft_strnew(k)))
        exit(0);
    while (--j >= 0)
    {
        --i;
        index = ft_get_index(ft_char_to_index(nb1[i], g_base) + ft_char_to_index(nb2[j], g_base) + remaind, base);
        new->nbr[--k] = g_base[index];
        remaind = ft_get_remainder(ft_char_to_index(nb1[i], g_base) + ft_char_to_index(nb2[j], g_base) + remaind, base);
    }
    while (--i >= 0)
    {
        index = ft_get_index(ft_char_to_index(nb1[i], g_base) + 0 + remaind, base);
        new->nbr[--k] = g_base[index];
        remaind = ft_get_remainder(ft_char_to_index(nb1[i], g_base) + 0 + remaind, base);
    }
	if (remaind)
        new->nbr[--k] = g_base[remaind];
	new->nbr = set_begg_properly(new->nbr);
    if (res_sign)
        new->sign = 1;
    // free(nb1);
    // free(nb2);
    return (new);
}

t_nbrs  *add_main(t_nbrs *nb1, t_nbrs *nb2)
{
    if (nb1->sign && nb2->sign)
        return (primordial_oper_aka_add(nb1->nbr, nb2->nbr, 1));
    else if (!nb1->sign && !nb2->sign)
        return (primordial_oper_aka_add(nb1->nbr, nb2->nbr, 0));
    else if (nb1->sign)
        return (subtraction(nb2, nb1));
    else
        return (subtraction(nb1, nb2));
}