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

static t_column *ft_malloc_column(char *nameColumn, char *typeColumn)
{
	t_column	*new;

	new = (t_column*)malloc(sizeof(t_column) * 1);
	if (!new)
		return (NULL);
	new->nameColumn = nameColumn;
	new->typeColumn = typeColumn;
	new->amountRecords = 0;
	new->firstRow = NULL;
	new->lastRow = NULL;
	new->nextColumn = NULL;
	return (new);
}

t_column		*ft_return_column(t_table *table, char *nameColumn)
{
	t_column	*column;

	if (!table || !nameColumn)
		return (NULL);
	column = table->firstColumn;
	while(column)
	{
		if (ft_strcmp(column->nameColumn, nameColumn) == ISEQUAL)
			return (column);
		column = column->nextColumn;
	}
	return (NULL);
}

static void 	ft_create_column(t_db *database, t_table *table, char *nameColumn, char *typeColumn)
{
	t_column	*new;
	t_column	*id;

	if (!(new = ft_malloc_column(nameColumn, typeColumn)))
		return (ft_set_error(database, "Memory allocation error"));
	if (table->amountColumns == 0)
	{
		if (!(id = ft_malloc_column("id", "int")))
		{
			free(new);
			new = NULL;
			return (ft_set_error(database, "Memory allocation error"));
		}
		id->nextColumn = new;
		table->firstColumn = id;
		table->lastColumn = new;
		table->amountColumns = 2;
	}
	else
	{
		table->lastColumn->nextColumn = new;
		table->lastColumn = new;
		table->amountColumns += 1;
	}
	table->empty = False;
}

int		ft_check_type_of_column(char *typeColumn)
{
	if (!typeColumn)
		return (0);
	if (ft_is_all_print(typeColumn) == 0)
		return (0);
	if (ft_strlen(typeColumn) < 1)
		return (0);
	if (ft_strcmp(typeColumn, "string") == 0)
		return (STRING);
	else if (ft_strcmp(typeColumn, "int") == 0)
		return (INT);
	return (0);
}

void 			ft_new_column(t_db *database, char *nameTable, char *nameColumn, char *typeColumn)
{
	t_table		*table;

	if (!database)
		return ;
	if (!nameColumn)
		return (ft_set_error(database, "No column name"));
	if (!nameTable)
		return (ft_set_error(database, "No table name"));
	if (ft_check_type_of_column(typeColumn) == 0)
		return (ft_set_error(database, "Bad type of column"));
	if (ft_strlen(nameColumn) < 1)
		return (ft_set_error(database, "Column name too short"));
	if (ft_is_all_print(nameColumn) == NONPRINTABLE)
		return (ft_set_error(database, "Bad column name"));
	if (!(table = ft_return_table(database, nameTable)))
		return (ft_set_error(database, "Table name does not exist"));
	ft_create_column(database, table, nameColumn, typeColumn);
}
