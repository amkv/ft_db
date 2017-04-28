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

void			ft_db_action_select(t_query *query, t_query *list)
{
	if (ft_strcmp(query->object, DATABASE) == 0)
	{
		ft_printf("!SELECT DATABASE\n");
	}
	else if (ft_strcmp(query->object, TABLE) == 0)
	{
		ft_printf("!SELECT TABLE\n");
	}
	else if (ft_strcmp(query->object, COLUMN) == 0)
	{
		ft_printf("!SELECT COLUMN\n");
	}
	else if (ft_strcmp(query->object, RECORD) == 0)
	{
		ft_printf("!SELECT RECORD\n");
	}
	else
		ft_printf(RED"!BAD OBJECT (SELECT)\n"CLN);
}
