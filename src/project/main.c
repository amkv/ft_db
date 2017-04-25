/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:44:18 by akalmyko          #+#    #+#             */
/*   Updated: 2017/03/17 18:02:48 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

//static void 	ft_new_column(t_db *database, char *tableName, char *columnName)
//{
//	t_table		*table;
//
//	if (!database || !columnName || !tableName)
//		return ;
//	table = ft_return_table(database, tableName);
//	if (table)
//	{
//
//	}
//}

int	main(void)
{
	t_db 	*database;

	database = ft_init_db("Test");
	if (!database)
		return (EXIT_FAILURE);
	ft_new_table(database, "First table");
	ft_new_table(database, "Second table");
	ft_new_table(database, "Third table");
//	ft_new_column(database, "First table", "Column 1");
	ft_printf("%s\n", database->name);
	ft_printf("%s\n", database->firstTable->nameTable);
	ft_printf("%s\n", database->lastTable->nameTable);
	ft_printf("%d\n", database->amountTables);
	return (EXIT_SUCCESS);
}
