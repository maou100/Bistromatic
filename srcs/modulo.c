/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 04:12:15 by feedme            #+#    #+#             */
/*   Updated: 2018/10/19 04:26:50 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bistro.h"

t_nbrs  *node_with_zero(void)
{
    t_nbrs  *new;

    if (!(new = (t_nbrs*)malloc(sizeof(t_nbrs))))
        exit(0);
    if (!(new->nbr = (char*)malloc(2)))
        exit(0);
    new->nbr[0] = g_base[0];
    new->nbr[1] = '\0';
    new->sign = 0;
    return (new);
}

char    *get_sub_dividend(char *nb1, char *nb2)
{
    int     i;
    char    booly;

    booly = 0;
    i = -1;
   while (nb2[++i])
    {
        if (ft_char_to_index(nb1[i], g_base) < ft_char_to_index(nb2[i], g_base) && !nb1[i + 1] && !booly)
            return (ft_one_char_str(g_base[0]));
        else if (ft_char_to_index(nb1[i], g_base) > ft_char_to_index(nb2[i], g_base))
            booly = 1;
    }
    if (ft_char_to_index(nb1[i - 1], g_base) < ft_char_to_index(nb2[i - 1], g_base))
        return (ft_strsub(nb1, 0, i + 1));
    else
        return (ft_strsub(nb1, 0, i));
}

char    *do_sub_div(char *nb1_tmp, char *rest, char *nb2, char *c)
{
    int     index;
    char    *new;
    char    *tmp;
    char    *tmp2;

    index = ft_div_by_1_digit(nb2[0], (tmp = ft_strsub(nb1_tmp, 0, 2)));
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

t_nbrs    *modulo(char *nb1, char *nb2, char res_sign)
{
    int     i;
    t_nbrs  *rest;
    char    *tmp;
    char    digit;
    char    *tmp2;

    if (ft_char_to_index(nb1[0], g_base) == 0)
        return (ft_one_char_str(g_base[0]));
    if (ft_char_to_index(nb2[0], g_base) == 0)
        ft_exit_msg("syntax error\n");
    i = -1;
    rest = new_t_nbr();
    if (!(rest->nbr = ft_strdup(nb1)))
        exit(0);
    while (ft_anybase_strcmp(rest->nbr, nb2) >= 0)
    {
        tmp = get_sub_dividend(rest->nbr, nb2);
        free(rest->nbr);
        rest->nbr = do_sub_div(tmp, rest->nbr, nb2, &digit);
        free(tmp);
    }
    if (res_sign)
        rest->sign = 1;
    return (rest);
}

t_nbrs	*mod_main(t_nbrs *nb1, t_nbrs *nb2)
{
	if (ft_anybase_strcmp(nb1->nbr, nb2->nbr) < 0)
	{
		if ((!nb1->sign && !nb2->sign) || (nb1->sign && nb2->sign))
		{
            nb1->next = NULL;
            return (nb1);
        }
        return ((nb1->sign ? subtraction(nb2->nbr, nb1->nbr) : subtraction(nb1->nbr, nb2->nbr)));
	}
	else if (ft_anybase_strcmp(nb1->nbr, nb2->nbr) > 0)
	{
		if (!nb1->sign && !nb2->sign)
			return (modulo(nb1->nbr, nb2->nbr, 0));
		else if (nb1->sign && nb2->sign)
			return (modulo(nb1->nbr, nb2->nbr, 1));
		else if (nb1->sign)
			return (subtraction(nb2->nbr, modulo(nb1->nbr, nb2->nbr, 0)));
		else
			return (subtraction(modulo(nb1->nbr, nb2->nbr, 0), nb2->nbr));
	}
	else
    	return (node_with_zero());
}