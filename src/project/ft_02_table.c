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

t_table			*ft_return_table(t_db *database, char *name)
{
	t_table		*table;

	if (!database || !name)
		return NULL;
	table = database->firstTable;
	while(table)
	{
		if (ft_strcmp(table->nameTable, name) == ISEQUAL)
			break ;
		table = table->nextTable;
	}
	return (table);
}

static t_table	*ft_malloc_table(char *name)
{
	t_table		*new;

	if (!name)
		return (NULL);
	new = (t_table*)malloc(sizeof(t_table) * 1);
	if (!new)
		return (NULL);
	new->nameTable = name;
	new->nextTable = NULL;
	new->amountColumn = 0;
	new->firstColumn = NULL;
	new->lastColumn = NULL;
	return (new);
}

void			ft_new_table(t_db *database, char *name)
{
	t_table		*new;

	if (!database || !name)
		return ;
	if (ft_return_table(database, name))
		return ;
	if (!(new = ft_malloc_table(name)))
		return ;
	if (!database->firstTable)
	{
		database->firstTable = new;
		database->lastTable = new;
	}
	else
	{
		database->lastTable->nextTable = new;
		database->lastTable = database->lastTable->nextTable;
	}
	database->amountTables += 1;
}
