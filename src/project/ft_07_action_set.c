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

void			ft_db_action_set(t_query *query, t_query *list)
{
	if (ft_strcmp(query->object, TYPE) == 0)
	{
		query->typeColumn = list->tag;
		query->lock = True;
		ft_printf("!SET TYPE\n");
	}
	else
		ft_printf(RED"!BAD OBJECT (SET)\n"CLN);
}
