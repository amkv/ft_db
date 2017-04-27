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

void			ft_print_all_records(t_db *database)
{
	t_table		*table;
	t_column	*column;
	t_record	*rows;
	t_record	*record;

	if (!database)
		return ;
	table = database->firstTable;
	ft_printf("\nDATABASE: %s\n\n", database->name);
	while (table)
	{
		ft_printf("TABLE: [%s], COLUMNS: %d, ROWS: %d, RECORDS: %d\n", table->nameTable, table->amountColumns, table->amountRows, table->amountRecords);
		ft_printf("+--------------------------------------+\n| ");
		column = table->firstColumn;
		if (column)
			rows = column->firstRow;
		else
			rows = NULL;
		while(column)
		{
			ft_printf("<%s> (%s) | ", column->nameColumn, column->typeColumn);
			column = column->nextColumn;

			if (!column)
				ft_printf("\n");
		}
		while(rows)
		{
			record = rows->firstID;
			while(record)
			{
				if (record->empty)
					ft_printf(GRY"[id: %d(%d) (%s)]"CLN" NONE "GRY"|"CLN" ", record->isID, record->id, record->typeRecord);
				else
				{
					ft_printf(GRY"[id: %d(%d) (%s)] "CLN, record->isID, record->id, record->typeRecord);
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
		table = table->nextTable;
		ft_printf("\n\n");
	}
}
