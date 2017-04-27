/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   *.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem Kalmykov <kalmykov.artem@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/00/00 00:00:00 by akalmyko          #+#    #+#             */
/*   Updated: 2017/00/00 00:00:00 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

t_table			*ft_return_table(t_db *database, char *nameTable)
{
	t_table		*table;

	if (!database || !nameTable)
		return NULL;
	table = database->firstTable;
	while(table)
	{
		if (ft_strcmp(table->nameTable, nameTable) == ISEQUAL)
			return (table);
		table = table->nextTable;
	}
	return (NULL);
}

static t_table	*ft_malloc_table(char *nameTable)
{
	t_table		*new;

	if (!nameTable)
		return (NULL);
	new = (t_table*)malloc(sizeof(t_table) * 1);
	if (!new)
		return (NULL);
	new->nameTable = nameTable;
	new->amountColumns = 0;
	new->amountRecords = 0;
	new->amountRows = 0;
	new->empty = True;
	new->firstColumn = NULL;
	new->lastColumn = NULL;
	new->nextTable = NULL;
	return (new);
}

void			ft_new_table(t_db *database, char *nameTable)
{
	t_table		*new;

	if (!database)
		return ;
	if (!nameTable)
		return (ft_set_error(database, "No table name"));
	if (ft_strlen(nameTable) < 1)
		return (ft_set_error(database, "Table name too short"));
	if (ft_is_all_print(nameTable) == NONPRINTABLE)
		return (ft_set_error(database, "Bad name for table"));
	if (ft_return_table(database, nameTable))
		return (ft_set_error(database, "Table name already exist"));
	if (!(new = ft_malloc_table(nameTable)))
		return (ft_set_error(database, "Memory allocation error"));
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
