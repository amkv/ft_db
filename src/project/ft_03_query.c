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

void			ft_db_null_query(t_query *query)
{
	if (!query)
		return ;
	query->action = NULL;
	query->object = NULL;
	query->tag = NULL;
	query->lock = False;

	query->database = NULL;
	query->table = NULL;
	query->column = NULL;
	query->row = NULL;
	query->record = NULL;

	query->nameDB = NULL;
	query->nameTable = NULL;
	query->nameColumn = NULL;
	query->typeColumn = NULL;

	query->error = False;
	query->error_name = NULL;

	query->firstQuery = NULL;
	query->next = NULL;
}

static t_query 	*new_query(void)
{
	t_query *query;

	query = (t_query*)malloc(sizeof(t_query) * 1);
	if (!query)
		return (NULL);
	ft_db_null_query(query);
	return (query);
}

t_query			*ft_db_add_query(t_query *query, char *action, char *object, char *tag)
{
	t_query		*new;

	new = new_query();
	if (!new)
		return (NULL);
	new->action = action;
	new->object = object;
	new->tag = tag;
	if (!query)
	{
		query = new;
		query->firstQuery = new;
	}
	else
	{
		query->next = new;
		new->firstQuery = query->firstQuery;
		query = new;
	}
	return (query);
}
