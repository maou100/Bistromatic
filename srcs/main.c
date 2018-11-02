/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 18:20:03 by feedme            #+#    #+#             */
/*   Updated: 2018/10/17 05:10:13 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bistro.h"
#include <stdio.h>


t_nbrs  *operations(t_nbrs *nb1, t_nbrs *nb2, char oper)
{
    t_nbrs  *new;

    if (oper == '-')
        new = sub_main(nb1, nb2);
    else if (oper == '+')
        new = add_main(nb1, nb2);
    else if (oper == '*')
        new = mult_main(nb1, nb2);
    else if (oper == '/')
        new = div_main(nb1, nb2);
    else
        new = mod_main(nb1, nb2);
    if (new->nbr[0] == g_base[0])
        new->sign = 0;
    return (new);
}







int     main(int ac, char **av)
{
    char    *input;
    t_nbrs  *nbrs;

    if (ac != 3)
        exit(0);
    if (!(g_base = ft_strdup(av[1])))
        exit(0);
    input = check_errors(av);

   // nbrs = build_list(input);


LES NOMBRES SONT CONSIDERES COMMES POSITIFS DANS TOUT LES CALCULS!!!!!!!!!!!!!!!!

FAIRE EN SORTE DE POUVOIR FAIRE PLUSIEURS DIFFERENTS CALCULS
EN UNE FOIS (EN LES SEPARANTS AVEC DES \N DANS INPUT) ET DONC CHANGER GET_INPUT


FREE DANS LA FONCTION QUI ENVOI NB1 ET NB2 DANS LES OPERATIONS
PLUTOT QUE DANS CETTES DERNIERES


ENLEVER LE - TOUT DEVANS ET FAIRE TOUT LE CALCUL SANS PUIS METTRE AU NEGATIF A LA FIN
|
L>>>   AUSSI METTRE UN MOINS DEVANT SI LE RESULTAT.NODE.SIGN EST NEGATIF

//  printf("%s\n", input);
    free(input);
//  while (1);
    return (0);
}
