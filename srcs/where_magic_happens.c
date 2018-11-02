/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_magic_happens.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 12:55:48 by feedme            #+#    #+#             */
/*   Updated: 2018/10/19 13:31:06 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bistro.h"



int     ft_anybase_strcmp(char *nb1, char *nb2)
{
    int     i;
    int     len1;
    int     len2;

    i = -1;
    len1 = ft_strlen(nb1);
    len2 = ft_strlen(nb2);
    if (len1 != len2)
        return (len1 - len2);
    else
    {
        while (nb1[++i])
        {
            if (ft_char_to_index(nb1[i], g_base) < ft_char_to_index(nb2[i], g_base))
                return (-1);
            else if (ft_char_to_index(nb1[i], g_base) > ft_char_to_index(nb2[i], g_base))
                return (1);
        }
        return (0);
    }
}

int		ft_char_to_index(char c, char *base)
{
	int		i;

	i = 0;
	while (c != base[i])
		i++;
	return (i);
}

int     ft_get_index(int shift, int base)
{
    int     index;

    index = shift % base;
    return (index);
}

int     ft_get_remainder(int shift, int base)
{
    int     remaind;

    remaind = shift / base;
    return (remaind); 
}

