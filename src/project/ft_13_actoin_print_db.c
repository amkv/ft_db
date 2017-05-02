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

void			ft_print_columns(t_table *table, t_record **rows)
{
	t_column	*column;

	column = table->firstColumn;
	if (column)
		*rows = column->firstRow;
	else
		*rows = NULL;
	while(column)
	{
		ft_printf("[%s] "GRY"<%s>"CLN, column->nameColumn, column->typeColumn);
		ft_printf(GRY" | "CLN);
		column = column->nextColumn;
		if (!column)
			ft_printf("\n");
	}
}

void			ft_print_record_specific(t_record *record)
{
	if (record->isID)
		ft_printf(GRY"[%d]"CLN, record->id);
	else if (record->empty)
		ft_printf(GRY"NONE"CLN, record->typeRecord);
	else
	{
		if (ft_strcmp(record->typeRecord, "string") == 0)
			ft_printf(GRN"%s"CLN, (char*)record->value);
		else if (ft_strcmp(record->typeRecord, "int") == 0)
			ft_printf(GRN"%d"CLN, ft_atoi(record->value));
	}
}

void			ft_print_records(t_record *rows)
{
	t_record	*record;

	while(rows)
	{
		record = rows->firstID;
		while(record)
		{
			ft_print_record_specific(record);
			ft_printf(GRY" | "CLN);
			record = record->right;
		}
		rows = rows->firstID->down;
		ft_printf("\n");
	}
}

void			ft_print_table_specific(t_table *table)
{
	ft_printf(TABLELINE);
	ft_printf("TABLE: [%s], ", table->nameTable);
	ft_printf(GRY"COLUMNS: %d, ", table->amountColumns);
	ft_printf("ROWS: %d, ", table->amountRows);
	ft_printf("RECORDS: %d\n"CLN, table->amountRecords);
}

void			ft_db_print_all_db(t_db *database)
{
	t_table		*table;
	t_record	*rows;

	if (!database)
		return ;
	table = database->firstTable;
	ft_printf(TABLELINE);
	ft_printf("DATABASE: %s\n", database->name);
	while (table)
	{
		ft_print_table_specific(table);
		ft_print_columns(table, &rows);
		ft_printf(TABLELINE);
		ft_print_records(rows);
		ft_printf(TABLELINE);
		table = table->nextTable;
	}
}
