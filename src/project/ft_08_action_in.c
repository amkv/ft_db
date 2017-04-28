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
		query->nameTable = list->tag;
		query->lock = True;
		ft_printf("!IN TABLE\n");
	}
	else if (ft_strcmp(query->object, COLUMN) == 0)
	{
		query->nameColumn = list->tag;
		query->lock = True;
		ft_printf("!IN COLUMN\n");
	}
	else
		ft_printf(RED"!BAD OBJECT (IN)\n"CLN);
}
