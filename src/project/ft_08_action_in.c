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
	else
		ft_print_debug_info(*query->database, RED"BAD OBJECT (IN)"CLN);
}
