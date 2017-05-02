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

static void		ft_db_action_flush_database_columns(t_table *table, t_record **rows)
{
	t_column	*column;
	t_column	*victim;

	column = table->firstColumn;
	if (column)
		*rows = column->firstRow;
	else
		*rows = NULL;
	while(column)
	{
		free(column->nameColumn);
		free(column->typeColumn);
		victim = column;
		column = column->nextColumn;
		free(victim);
	}
}

static void		ft_db_action_flush_database_records(t_record *rows)
{
	t_record	*record;
	t_record	*victim;

	while(rows)
	{
		record = rows->firstID;
		while(record)
		{
			victim = record;
			free(victim->typeRecord);
			free(victim->value);
			if (record->isID)
			{
				record = record->right;
				continue ;
			}
			record = record->right;
			free(victim);
		}
		victim = rows;
		rows = rows->firstID->down;
		free(victim);
	}
}

void			ft_db_action_flush_database_all(t_db *database)
{
	t_table		*table;
	t_table		*victim;
	t_record	*rows;

	if (!database)
		return ;
	table = database->firstTable;
	while (table)
	{
		ft_db_action_flush_database_columns(table, &rows);
		ft_db_action_flush_database_records(rows);
		victim = table;
		table = table->nextTable;
		free(victim->nameTable);
		free(victim);
	}
	free(database->name);
	free(database);
}

static void 	ft_db_action_flush_database(t_query *query, t_query *list)
{
	if (!*query->database)
		return ;
	if (ft_strcmp((*query->database)->name, query->tag) == 0)
	{
		ft_db_action_flush_database_all(*query->database);
		/* ft_print_debug_info(*query->database, "FLUSH DATABASE"); */
	}
	else
		ft_print_debug_info(*query->database, RED"BAD DATABASE"CLN);

}

void			ft_db_action_flush(t_query *query, t_query *list)
{
	if (ft_strcmp(query->object, DATABASE) == 0)
		ft_db_action_flush_database(query, list);
	else
		ft_print_debug_info(*query->database, RED"BAD OBJECT (FLUSH)"CLN);
}
