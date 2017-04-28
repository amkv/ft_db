#include "db.h"

void	ft_db_dump(t_db *database, char *file)
{
	int			fd;
	t_table		*table;
	t_record	*record;
	t_record	*row;
	t_column	*column;
	char		*line;

	if (!database)
		return ;
	if ((fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)
		return ;
	line = ft_strdup("(db_name='");
	line = ft_strjoin(line, database->name);
	line = ft_strjoin(line, "')\n");
	write(fd, line, strlen(line));
	table = database->firstTable;
	while (table)
	{
		line = ft_strdup("(table_name='");
		line = ft_strjoin(line, table->nameTable);
		line = ft_strjoin(line, "',columns='");
		line = ft_strjoin(line, ft_itoa(table->amountColumns));
		line = ft_strjoin(line, "',rows='");
		line = ft_strjoin(line, ft_itoa(table->amountRows));
		line = ft_strjoin(line, "',records='");
		line = ft_strjoin(line, ft_itoa(table->amountRecords));
		line = ft_strjoin(line, "')\n");
		write(fd, line, strlen(line));

		column = table->firstColumn;
		if (column)
		{
			line = ft_strdup("(columns='");
			row = column->firstRow;
			while (column)
			{
				line = ft_strjoin(line, column->nameColumn);
				line = ft_strjoin(line, "':'");
				line = ft_strjoin(line, column->typeColumn);
				if (column->nextColumn)
					line = ft_strjoin(line, "','");
				else
					line = ft_strjoin(line, "')\n");
				column = column->nextColumn;
			}
			write(fd, line, strlen(line));
			while (row)
			{
				line = ft_strdup("('");
				record = row->firstID;
				while (record)
				{
					if (record->isID)
						line = ft_strjoin(line, ft_itoa(record->id));
					else if (!record->empty)
					{
						if (!ft_strcmp(record->typeRecord, "int"))
							line = ft_strjoin(line, ft_itoa((int)record->value));
						else if (!ft_strcmp(record->typeRecord, "string"))
							line = ft_strjoin(line, (char *)record->value);
					}
					if (record->right)
						line = ft_strjoin(line, "','");
					else
						line = ft_strjoin(line, "')\n");
					record = record->right;
				}
				write(fd, line, strlen(line));
				row = row->firstID->down;
			}
		}
		table = table->nextTable;
	}
}
