/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_20_dump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 21:43:44 by vtenigin          #+#    #+#             */
/*   Updated: 2017/04/27 21:45:20 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

static void		ft_write_to_file(int fd, char *text)
{
	size_t		len;

	len = ft_strlen(text);
	write(fd, text, len);
}

static void		ft_dump_records(int fd, t_record *row)
{
	t_record	*record;
	char 		*tmp;

	while (row)
	{
		ft_write_to_file(fd, "(\'");
		record = row->firstID;
		while (record)
		{
			if (record->isID)
			{
				ft_write_to_file(fd, tmp = ft_itoa(record->id));
				free(tmp);
			}
			else if (!record->empty)
			{
				if (!ft_strcmp(record->typeRecord, "int"))
					ft_write_to_file(fd, (char*)record->value);
				else if (!ft_strcmp(record->typeRecord, "string"))
					ft_write_to_file(fd, (char*)record->value);
			}
			if (record->right)
				ft_write_to_file(fd, "\',\'");
			else
				ft_write_to_file(fd, "\')\n");
			record = record->right;
		}
		row = row->firstID->down;
	}
}

static void		ft_dump_columns(int fd, t_column *column)
{
	t_record	*row;

	if (column)
	{
		ft_write_to_file(fd, "(columns=\'");
		row = column->firstRow;
		while (column)
		{
			ft_write_to_file(fd, column->nameColumn);
			ft_write_to_file(fd, "\':\'");
			ft_write_to_file(fd, column->typeColumn);
			if (column->nextColumn)
				ft_write_to_file(fd, "\',\'");
			else
				ft_write_to_file(fd, "')\n");
			column = column->nextColumn;
		}
		ft_dump_records(fd, row);
	}
}

void			ft_db_dump(t_db *database, char *file)
{
	int			fd;
	t_table		*table;
	char 		*tmp;

	if (!database)
		return ;
	if ((fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)
		return ;
	ft_write_to_file(fd, "(db_name='\"");
	ft_write_to_file(fd, database->name);
	ft_write_to_file(fd, "\')\n");
	table = database->firstTable;
	while (table)
	{
		ft_write_to_file(fd, "(table_name=\'");
		ft_write_to_file(fd, table->nameTable);
		ft_write_to_file(fd, "\',columns=\'");
		ft_write_to_file(fd, tmp = ft_itoa(table->amountColumns));
		free(tmp);
		ft_write_to_file(fd, "\',rows=\'");
		ft_write_to_file(fd, tmp = ft_itoa(table->amountRows));
		free(tmp);
		ft_write_to_file(fd, "\',records=\'");
		ft_write_to_file(fd, tmp = ft_itoa(table->amountRecords));
		free(tmp);
		ft_write_to_file(fd, "')\n");
		ft_dump_columns(fd, table->firstColumn);
		table = table->nextTable;
	}
	close(fd);
}
