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

static void		ft_print_columns(t_table *table, t_record **rows)
{
	t_column	*column;

	column = table->firstColumn;
	if (column)
		*rows = column->firstRow;
	else
		*rows = NULL;
	while(column)
	{
		ft_printf("<%s> (%s) | ", column->nameColumn, column->typeColumn);
		column = column->nextColumn;
		if (!column)
			ft_printf("\n");
	}
}

static void		ft_print_records(t_record *rows)
{
	t_record	*record;

	while(rows)
	{
		record = rows->firstID;
		while(record)
		{
			if (record->isID)
				ft_printf(GRY"[%d] | "CLN, record->id);
			else if (record->empty)
				ft_printf(GRY"NONE"CLN" | ", record->typeRecord);
			else
			{
				if (ft_strcmp(record->typeRecord, "string") == 0)
					ft_printf(GRN"%s"CLN" | ", (char*)record->value);
				else if (ft_strcmp(record->typeRecord, "int") == 0)
					ft_printf(GRN"%d"CLN" | ", (int)record->value);
			}
			record = record->right;
		}
		rows = rows->firstID->down;
		ft_printf("\n");
	}
}

void			ft_db_print_all_db(t_db *database)
{
	t_table		*table;
	t_record	*rows;

	if (!database)
		return ;
	table = database->firstTable;
	ft_printf("\nDATABASE: %s\n\n", database->name);
	while (table)
	{
		ft_printf("TABLE: [%s], ", table->nameTable);
		ft_printf("COLUMNS: %d, ", table->amountColumns);
		ft_printf("ROWS: %d, ", table->amountRows);
		ft_printf("RECORDS: %d\n", table->amountRecords);
		ft_printf("+------------------------------------------------------+\n");
		ft_print_columns(table, &rows);
		ft_print_records(rows);
		table = table->nextTable;
		ft_printf("\n\n");
	}
}
