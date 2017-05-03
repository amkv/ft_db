/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_13_actoin_print_db.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem Kalmykov <akalmyko@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 13:00:06 by akalmyko          #+#    #+#             */
/*   Updated: 2017/05/03 15:42:57 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

void			ft_print_columns(t_table *table, t_record **rows)
{
	t_column	*column;
	t_column	*column2;

	column = table->firstColumn;
	if (column)
		*rows = column->firstRow;
	else
		*rows = NULL;
	column2 = column;
	while(column)
	{
		ft_printf("[%s]", column->nameColumn);
		ft_printf(GRY" | "CLN);
		column = column->nextColumn;
		if (!column)
			ft_printf("\n");
	}
	while(column2)
	{
		if (ft_strcmp(column2->typeColumn, "string") == 0)
			ft_printf(""GRY"<%s>"CLN, "str");
		else
			ft_printf(""GRY"<%s>"CLN, column2->typeColumn);
		ft_printf(GRY" | "CLN);
		column2 = column2->nextColumn;
		if (!column2)
			ft_printf("\n");
	}
}

void			ft_print_record_specific(t_record *record)
{
	int 		space;

	space = 10;
	if (record->isID)
		ft_printf(GRY"[%d]"CLN, record->id);
	else if (record->empty)
		ft_printf(GRY"%-*s"CLN, space, "NONE");
	else
	{
		if (ft_strcmp(record->typeRecord, "string") == 0)
			ft_printf(GRN"%-*s"CLN, space, (char*)record->value);
		else if (ft_strcmp(record->typeRecord, "int") == 0)
			ft_printf(GRN"%-*d"CLN, space, ft_atoi(record->value));
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
