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

int	 			ft_db_action(t_query *query, va_list list)
{
	void		**pointer;
	t_db		*database;

	if (!query)
		return (-1);
//	database = va_arg(list, t_db*);
//	if (!database && ft_strcmp(query->command, CREATE_DATABASE) != 0)
//		return (0);
	while(query)
	{
		if (ft_strcmp(query->command, CREATE_DATABASE) == 0)
		{
			pointer = (void**)va_arg(list, t_db*);
			*pointer = ft_init_db(query->tag);
		}
		else if (ft_strcmp(query->command, CREATE_TABLE) == 0)
		{

		}
		else if (ft_strcmp(query->command, CREATE_COLUMN) == 0)
			;
		else if (ft_strcmp(query->command, ADD_RECORD) == 0)
			;
		query = query->next;
	}
	return (0);
}
