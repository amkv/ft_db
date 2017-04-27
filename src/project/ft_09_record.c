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

static void		ft_create_record(t_db *database, t_table *table, t_column *column, void *record)
{
	column->lastRow->value = record;
	column->lastRow->empty = False;
	table->amountRecords += 1;
	column->amountRecords += 1;
}

void			ft_new_record(t_db *database, char *nameTable, char *nameColumn, char *typeColumn, void *record)
{
	t_column	*column;
	t_table		*table;

	if (!database)
		return ;
	if (!nameTable)
		return (ft_set_error(database, "No table name"));
	if (!nameColumn)
		return (ft_set_error(database, "No column name"));
	if (ft_check_type_of_column(typeColumn) == 0)
		return (ft_set_error(database, "Bad type of column"));
	if (!(table = ft_return_table(database, nameTable)))
		return (ft_set_error(database, "Table name does not exist"));
	if (!(column = ft_return_column(table, nameColumn)))
		return (ft_set_error(database, "Column name does not exist"));
	ft_create_row(database, table, column);
	ft_create_record(database, table, column, record);
//	ft_printf("row created\n");
}

/*
 * "types"
 * s string
 * c char
 * d/i int
 * ...
 */
