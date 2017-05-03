/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_12_action_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem Kalmykov <akalmyko@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:08:21 by akalmyko          #+#    #+#             */
/*   Updated: 2017/05/03 15:42:51 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

static void		ft_db_action_print_database(t_query *query, t_query *list)
{
	list->unused = False;
	ft_db_print_all_db(*query->database);
	ft_print_debug_info(*query->database, "PRINT DATABASE");
}

static void		ft_db_action_print_table(t_query *query, t_query *list)
{
	t_table		*table;
	t_record	*rows;

	query->nameTable = list->tag;
	table = ft_return_table(*query->database, query->nameTable);
	if (!table)
		return (ft_print_debug_info(*query->database, RED"BAD TABLE"CLN));
	ft_print_table_specific(table);
	ft_print_columns(table, &rows);
	ft_printf(TABLELINE);
	ft_print_records(rows);
	ft_printf(TABLELINE);
	ft_print_debug_info(*query->database, "PRINT TABLE");
}

static void		ft_db_action_print_column(t_query *query, t_query *list)
{
	t_table		*table;
	t_column	*column;
	t_record	*record;

	query->lock = False;
	table = ft_return_table(*query->database, query->nameTable);
	if (!table)
		return(ft_print_debug_info(*query->database, RED"BAD TABLE"CLN));
	query->nameColumn = list->tag;
	column = ft_return_column(table, query->nameColumn);
	if (!column)
		return (ft_print_debug_info(*query->database, RED"BAD COLUMN"CLN));
	record = column->firstRow;
	while(record)
	{
		if (!record->empty)
		{
			ft_print_record_specific(record);
			ft_printf("\n");
		}
		record = record->down;
	}
	query->lock = False;
	ft_print_debug_info(*query->database, "PRINT COLUMN");
}

static void		ft_db_action_print_row(t_query *query, t_query *list)
{
	t_table		*table;
	t_column	*column;
	t_record	*record;
	long long 	num;

	query->lock = False;
	table = ft_return_table(*query->database, query->nameTable);
	if (!table)
		return (ft_print_debug_info(*query->database, RED"BAD TABLE"CLN));
	column = table->firstColumn;
	if (!column)
		return (ft_print_debug_info(*query->database, RED"NO COLUMN"CLN));
	record = column->firstRow;
	if (!record)
		return (ft_print_debug_info(*query->database, RED"NO RECORDS"CLN));
	num = ft_atoi(list->tag);
	if (num <= 0 || (size_t)num > table->amountRows)
		return (ft_print_debug_info(*query->database, RED"BAD ID"CLN));
	while(record)
	{
		if (record->id == (size_t)num)
			break ;
		record = record->down;
	}
	if (!record)
		return (ft_print_debug_info(*query->database, RED"NO ROWS"CLN));
	while(record)
	{
		if (!record->empty)
		{
			ft_print_record_specific(record);
			ft_printf("\n");
		}
		record = record->right;
	}
	ft_print_debug_info(*query->database, "PRINT ROW");
}

static void		ft_db_action_print_record(t_query *query, t_query *list)
{
	list->unused = False;
	ft_print_debug_info(*query->database, "PRINT RECORD");
}

void			ft_db_action_print(t_query *query, t_query *list)
{
	if (ft_strcmp(query->object, DATABASE) == 0)
		ft_db_action_print_database(query, list);
	else if (ft_strcmp(query->object, TABLE) == 0)
		ft_db_action_print_table(query, list);
	else if (ft_strcmp(query->object, COLUMN) == 0)
		ft_db_action_print_column(query, list);
	else if (ft_strcmp(query->object, ROW) == 0)
		ft_db_action_print_row(query, list);
	else if (ft_strcmp(query->object, RECORD) == 0)
		ft_db_action_print_record(query, list);
	else
		ft_print_debug_info(*query->database, RED"BAD OBJECT (PRINT)"CLN);
}
