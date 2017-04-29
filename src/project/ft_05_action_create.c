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

static void		ft_db_action_create_database(t_query *query, t_query *list)
{
//	if (list->tag)
//	{
		query->nameDB = list->tag;
		*query->database = ft_init_db(query->nameDB);
//	}
	ft_print_debug_info(*query->database, "CREATE DATABASE");
}

static void		ft_db_action_create_table(t_query *query)
{
	query->nameTable = query->tag;
	ft_new_table(*query->database, query->tag);
	ft_print_debug_info(*query->database, "CREATE TABLE");
}

static void		ft_db_action_create_column(t_query *query, t_query *list)
{

	query->nameColumn = list->tag;
	ft_new_column(*query->database, query->nameTable, query->nameColumn, query->typeColumn);
	query->lock = False;
	free(query->nameTable);
	free(query->typeColumn);
	ft_print_debug_info(*query->database, "CREATE COLUMN");
}

void			ft_db_action_create(t_query *query, t_query *list)
{
	if (ft_strcmp(query->object, DATABASE) == 0)
		ft_db_action_create_database(query, list);
	else if (ft_strcmp(query->object, TABLE) == 0)
		ft_db_action_create_table(query);
	else if (ft_strcmp(query->object, COLUMN) == 0)
		ft_db_action_create_column(query, list);
	else
		ft_print_debug_info(*query->database, RED"BAD OBJECT (CREATE)"CLN);
}
