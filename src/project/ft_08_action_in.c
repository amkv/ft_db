/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_08_action_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem Kalmykov <akalmyko@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 15:18:22 by akalmyko          #+#    #+#             */
/*   Updated: 2017/05/03 15:39:36 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

void			ft_db_action_in(t_query *query, t_query *list)
{
	if (ft_strcmp(query->object, TABLE) == 0)
	{
		query->nameTable = ft_strdup(list->tag);
		query->memNameTable = True;
		query->lock = True;
		ft_print_debug_info(*query->database, "IN TABLE");
	}
	else if (ft_strcmp(query->object, COLUMN) == 0)
	{
		query->nameColumn = ft_strdup(list->tag);
		query->memNameColumn = True;
		query->lock = True;
		ft_print_debug_info(*query->database, "IN COLUMN");
	}
	else if (ft_strcmp(query->object, RECORD) == 0)
	{
		query->nameRecordTo = ft_strdup(list->tag);
		query->memNameRecordTo = True;
		query->lock = True;
		ft_print_debug_info(*query->database, "IN RECORD");
	}
	else
		ft_print_debug_info(*query->database, RED"BAD OBJECT (IN)"CLN);
}
