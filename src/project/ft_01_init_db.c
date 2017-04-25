/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:44:18 by akalmyko          #+#    #+#             */
/*   Updated: 2017/03/17 18:02:48 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

t_db			*ft_init_db(char *name)
{
	t_db		*new;

	if (!name)
		return (NULL);
	new = (t_db*)malloc(sizeof(t_db) * 1);
	if (!new)
		return (NULL);
	new->name = name;
	new->amountTables = 0;
	new->firstTable = NULL;
	new->lastTable = NULL;
	return (new);
}
