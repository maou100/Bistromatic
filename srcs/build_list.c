/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 05:05:13 by feedme            #+#    #+#             */
/*   Updated: 2018/10/17 05:06:25 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bistro.h"

t_nbrs      *new_t_nbr(void)
{
    t_nbrs  *new;

    if (!(new = (t_nbrs *)malloc(sizeof(t_nbrs))))
        exit(0);
    new->nbr = NULL;
    new->sign = 0;
    new->next = NULL;
    return (new);
}



t_nbrs		*build_list(char *input)
{
	t_nbrs  *head;
    t_nbrs  *new;
    t_nbrs  *tmp;
    int     i;

    new = new_node();
    head = new;
    i = 0;
    while (input[i])
    {
        if ()
        if (i > 0 && input[i - 1] == '-')
            new->sign = 1;
        
    }
    return (head);
}


t_