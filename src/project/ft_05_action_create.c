/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_05_action_create.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem Kalmykov <akalmyko@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 11:21:11 by akalmyko          #+#    #+#             */
/*   Updated: 2017/05/03 15:56:32 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

static void		ft_db_action_create_database(t_query *query, t_query *list)
{
	query->nameDB = list->tag;
	*query->database = ft_init_db(query->nameDB);
	ft_print_debug_info(*query->database, "CREATE DATABASE");
}

static void		ft_db_action_create_table(t_query *query)
{
	query->nameTable = query->tag;
	ft_new_table(*query->database, query->nameTable);
	ft_print_debug_info(*query->database, "CREATE TABLE");
}

static void		ft_db_action_create_column(t_query *query, t_query *list)
{

	query->nameColumn = ft_strdup(list->tag);
	query->memNameColumn = True;
	ft_new_column(*query->database, query->nameTable, query->nameColumn, query->typeColumn);
	query->lock = False;
	ft_print_debug_info(*query->database, "CREATE COLUMN");
}

static void		ft_db_action_create_record(t_query *query, t_query *list)
{
	query->record = (void*)list->tag;
	ft_new_record(*query->database, query->nameTable, query->nameColumn, query->typeColumn, query->record);
	query->lock = False;
	ft_print_debug_info(*query->database, "CREATE RECORD");
}

void			ft_db_action_create(t_query *query, t_query *list)
{
	if (ft_strcmp(query->object, DATABASE) == 0)
		ft_db_action_create_database(query, list);
	else if (ft_strcmp(query->object, TABLE) == 0)
		ft_db_action_create_table(query);
	else if (ft_strcmp(query->object, COLUMN) == 0)
		ft_db_action_create_column(query, list);
	else if (ft_strcmp(query->object, RECORD) == 0)
		ft_db_action_create_record(query, list);
	else
		ft_print_debug_info(*query->database, RED"BAD OBJECT (CREATE)"CLN);
}
