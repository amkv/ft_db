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

static t_column *ft_malloc_column(char *nameColumn)
{
	t_column	*new;

	new = (t_column*)malloc(sizeof(t_column) * 1);
	if (!new)
		return (NULL);
	new->nameColumn = nameColumn;
	new->downRecord = NULL;
	new->nextColumn = NULL;
	return (new);
}

static void 	ft_create_column(t_db *database, t_table *table, char *nameColumn)
{
	t_column	*new;
	t_column	*id;

	if (!(new = ft_malloc_column(nameColumn)))
		return (ft_set_error(database, "Memory allocation error"));
	if (table->amountColumn == 0)
	{
		if (!(id = ft_malloc_column("id")))
		{
			free(new);
			new = NULL;
			return (ft_set_error(database, "Memory allocation error"));
		}
		id->nextColumn = new;
		table->firstColumn = id;
		table->lastColumn = new;
		table->amountColumn = 2;
	}
	else
	{
		table->lastColumn->nextColumn = new;
		table->lastColumn = new;
		table->amountColumn += 1;
	}
}

void 			ft_new_column(t_db *database, char *nameTable, char *nameColumn)
{
	t_table		*table;

	if (!database)
		return ;
	if (!nameColumn)
		return (ft_set_error(database, "No column name"));
	if (!nameTable)
		return (ft_set_error(database, "No table name"));
	if (ft_strlen(nameColumn) < 1)
		return (ft_set_error(database, "Column name too short"));
	if (ft_is_all_print(nameColumn) == NONPRINTABLE)
		return (ft_set_error(database, "Bad column name"));
	if (!(table = ft_return_table(database, nameTable)))
		return (ft_set_error(database, "Table name does not exist"));
	ft_create_column(database, table, nameColumn);
}
