/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_04_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem Kalmykov <akalmyko@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 10:03:34 by akalmyko          #+#    #+#             */
/*   Updated: 2017/05/03 15:56:23 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

void			ft_print_debug_info(t_db *database, char *info)
{
	if (database)
	{
		if (database->debug)
			ft_printf("ft_db [%s]\n", info);
		if (database->error)
		{
			ft_printf("ft_db [%s]\n", database->nameError);
			database->error = False;
			database->nameError = NULL;
		}
	}
}

static t_query	*ft_free_list_and_next(t_query *list, t_query *query)
{
	t_query		*next;

	if (ft_strcmp(list->object, RECORD) != 0 || query->memNameRecordTo
		|| ft_strcmp(list->action, "DELETE") == 0)
	{
		free(list->tag);
		list->tag = NULL;
	}
	next = list->next;
	free(list->action);
	list->action = NULL;
	free(list->object);
	list->object = NULL;
	free(list);
	return (next);
}

static bool 	ft_initialize_query(t_query *query, t_query *list, t_db **database)
{
	query->database = database;
	query->action = list->action;
	query->object = list->object;
	query->tag = list->tag;
	if (query->action == NULL || query->object == NULL)
		return (False);
	return (True);
}

int	 			ft_db_action(t_query *list, va_list ap)
{
	t_query		query;
	t_db		**database;

	if (!list)
		return (-1);
	ft_set_false_by_default_for_memory_allocation(&query);
	ft_db_null_query(&query);
	database = (t_db**)va_arg(ap, t_db*);
	while(list)
	{
		if (!ft_initialize_query(&query, list, database))
			ft_print_debug_info(*query.database, RED"BAD ACTION or BAD OBJECT or TAG"CLN);
		else if (ft_strcmp(query.action, CREATE) == 0)
			ft_db_action_create(&query, list);
		else if (ft_strcmp(query.action, ADD) == 0)
			ft_db_action_add(&query, list);
		else if (ft_strcmp(query.action, SET) == 0)
			ft_db_action_set(&query, list);
		else if (ft_strcmp(query.action, IN) == 0)
			ft_db_action_in(&query, list);
		else if (ft_strcmp(query.action, CHANGE) == 0)
			ft_db_action_change(&query, list);
		else if (ft_strcmp(query.action, SELECT) == 0)
			ft_db_action_select(&query, list);
		else if (ft_strcmp(query.action, DELETE) == 0)
			ft_db_action_delete(&query, list);
		else if (ft_strcmp(query.action, PRINT) == 0)
			ft_db_action_print(&query, list);
		else if (ft_strcmp(query.action, DUMP) == 0)
			ft_db_action_dump(&query, list);
		else if (ft_strcmp(query.action, FLUSH) == 0)
			ft_db_action_flush(&query, list);
		else if (ft_strcmp(query.action, TO) == 0)
			ft_db_action_to(&query, list);
		else
			ft_print_debug_info(*query.database, RED"BAD ACTION"CLN);
		if (!query.lock)
			ft_db_null_query(&query);
		list = ft_free_list_and_next(list, &query);
	}
	return (0);
}
