/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_21_init_db.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem Kalmykov <akalmyko@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 20:56:08 by akalmyko          #+#    #+#             */
/*   Updated: 2017/05/03 15:43:32 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

void			ft_set_error(t_db *database, char *nameError)
{
	if (!database)
		return ;
	database->error = True;
	database->nameError = nameError;
}

void			ft_clean_error(t_db *database)
{
	if (!database)
		return ;
	database->error = False;
	database->nameError = NULL;
}

t_db			*ft_init_db(char *nameDB)
{
	t_db		*new;

	if (!nameDB)
		return (NULL);
	if (ft_strlen(nameDB) < 1)
		return (NULL);
	if (ft_is_all_print(nameDB) == NONPRINTABLE)
		return (NULL);
	new = (t_db*)malloc(sizeof(t_db) * 1);
	if (!new)
		return (NULL);
	new->name = ft_strdup(nameDB);
	new->amountTables = 0;
	new->firstTable = NULL;
	new->lastTable = NULL;
	new->error = False;
	new->nameError = NULL;
	new->debug = False;
	return (new);
}
