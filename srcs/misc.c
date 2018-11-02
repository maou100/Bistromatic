/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 17:14:58 by feedme            #+#    #+#             */
/*   Updated: 2018/10/17 17:16:12 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bistro.h"

char    *char_filled_new(int len, char c)
{
    char    *new;
    int     i;

    i = -1;
    if (!(new = (char*)malloc(len + 1)))
        exit(0);
    new[len] = '\0';
    while (new[++i])
        new[i] = c;
    return (new);
}

char    *ft_one_char_str(char c)
{
    char    *new;

    if (!(new = (char*)malloc(2)))
        return (NULL);
    new[1] = '\0';
    new[0] = c;
    return (new);
}

char    *remove_xtra_zero(char *nb)
{
    char    *new;
    int     i;
    int     j;
    int     len;

    i = 0;
    j = -1;
    while (nb[i] == g_base[0])
        i++;
    len = ft_strlen(nb) - i;
    if (!(new = ft_strnew(len)))
        exit(0);
    i--;
    while (nb[++i])
        new[++j] = nb[i];
    free(nb);
    return (new);
}

char    *set_begg_properly(char *str)
{
    int     i;
    char    *new;

    i = 0;
    while (!str[i])
        i++;
    str = ft_shift_left(str, i);
    i = 0;
    while (str[i] == g_base[0])
        i++;
    str = ft_shift_left(str, i);
    return (str);
}

void    check_av1(char *str)
{
    int     i;
    int     j;

    i = -1;
    while (str[++i])
    {
        j = i - 1;
        while (str[++j])
        {
            if (j != i && str[i] == str[j])
                ft_exit_msg("syntax error\n");
        }
    }
}