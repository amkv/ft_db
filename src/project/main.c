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

int 			ft_is_all_print(const char *str)
{
	if (!str)
		return (0);
	while(ft_isprint(*str))
		str++;
	if (*str == '\0')
		return (1);
	else
		return (0);
}

static void		ft_print_all_records(t_db *database)
{
	t_table		*table;
	t_column	*column;

	if (!database)
		return ;
	table = database->firstTable;
	ft_printf("%s\n\n", database->name);
	while (table)
	{
		ft_printf("[%s]\n", table->nameTable);
		column = table->firstColumn;
		while(column)
		{
			ft_printf("<%s> ", column->nameColumn);
			column = column->nextColumn;
			if (!column)
				ft_printf("\n");
		}
		table = table->nextTable;
		ft_printf("\n");
	}
}

int	main(void)
{
	t_db 	*database;

	database = ft_init_db("My fisrt DB");
	if (!database)
		return (EXIT_FAILURE);
	ft_new_table(database, "First table");
	ft_new_table(database, "Second table");
	ft_new_table(database, "Third table");
	ft_new_table(database, "d");
	ft_new_table(database, NULL);
	ft_new_column(database, "First table", "Column 1");
	ft_new_column(database, "First table", "Column 2");
	ft_new_column(database, "First table", "d");
	ft_new_column(database, "Second table", "Column 1");
	ft_new_column(database, "Second table", "Column 2");
	ft_new_column(database, "dfg", "Column 2");
//	ft_new_record(database, "First table", "Column 2", "string", "Record");
	ft_print_all_records(database);
//	free(all);
	return (EXIT_SUCCESS);
}
