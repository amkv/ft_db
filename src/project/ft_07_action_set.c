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

void			ft_db_action_set_debug(t_query *query, t_query *list)
{
	query->typeColumn = ft_strdup(list->tag);
	query->memTypeColumn = True;
	query->lock = True;
	ft_print_debug_info(*query->database, "SET TYPE");
}

void			ft_db_action_set_type(t_db *database)
{
	if (database)
	{
		ft_printf("ft_db [DEBUG: ");
		if (database->debug)
		{
			ft_printf("OFF]\n");
			database->debug = False;
		}
		else
		{
			ft_printf("ON]\n");
			database->debug = True;
		}
	}
}

void			ft_db_action_set(t_query *query, t_query *list)
{
	if (ft_strcmp(query->object, TYPE) == 0)
		ft_db_action_set_debug(query, list);
	else if (ft_strcmp(query->object, DEBUG) == 0)
		ft_db_action_set_type(*query->database);
	else
		ft_print_debug_info(*query->database, RED"BAD OBJECT (SET)"CLN);
}
