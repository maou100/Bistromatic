/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplication.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 01:29:42 by feedme            #+#    #+#             */
/*   Updated: 2018/10/19 01:29:58 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bistro.h"

t_nbrs      *multiplication(char *nb1, char *nb2, char res_sign)
{
    int     i;
    int     i_save;
    int     j;
    int     k;
    int     k_save;
    char    **step1;
    int     next;
    char    *new;
    int     remaind;
    int     base;
    int     index;
    t_nbrs  *result;

    next = -1;
    ft_anybase_strcmp(nb1, nb2) >= 0 ? 0 : ft_str_swap(&nb1, &nb2); //strcmp faster than strlen
    if (!(i = ft_strlen(nb1)) || !(j = ft_strlen(nb2)) || (remaind = 0) || !(base = ft_strlen(g_base)))
        ft_exit_msg("syntax error\n");
    k = i * 2 + 1;
    k_save = k;
    if (!(step1 = (char**)malloc(sizeof(char*) * (j + 1))))
        exit(0);
    step1[j] = NULL;
    while (--j >= 0)
    {
        i = i_save;
        k = k_save;
        if(!(new = char_filled_new(ft_strlen(nb1) * 2 + 1, g_base[0])))
            exit(0);
        while (--i >= 0)
        {
            index = ft_get_index(ft_char_to_index(nb1[i], g_base) * ft_char_to_index(nb2[j], g_base) + remaind, base);
            new[--k] = g_base[index];
            remaind = ft_get_remainder(ft_char_to_index(nb1[i], g_base) * ft_char_to_index(nb2[j], g_base) + remaind, base);
        }
        if (remaind)
            new[--k] = g_base[remaind];
        k_save--;
	    new = set_begg_properly(new);
        step1[++next] = ft_strdup(new);
        free(new);
    }
    i = -1;
    result = new_t_nbr();
    result->nbr = ft_one_char_str(g_base[0]);
    while (step1[++i])
        result->nbr = primordial_oper_aka_add(result->nbr, step1[i]);
	result->nbr = set_begg_properly(result->nbr);
    if (res_sign)
        result->sign = 1;
    return (result);
}

t_nbrs  *mult_main(t_nbrs *nb1, t_nbrs *nb2)
{
    if ((nb1->sign && nb2->sign) || (!nb1->sign && !nb2->sign))
        return (multiplication(nb1, nb2, 0));
    else
        return (multiplication(nb1, nb2, 1));
}