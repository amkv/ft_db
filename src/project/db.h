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

#ifndef DB_H
# define DB_H

# include "../lib/libft/libft.h"
# include <stdarg.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>

# pragma GCC diagnostic ignored "-Wunused-parameter"
# pragma GCC diagnostic ignored "-Wunused-variable"
# pragma GCC diagnostic ignored "-Wunused-function"

# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0
# define ISEQUAL 0
# define NONPRINTABLE 0
# define STRING 1
# define INT 2
# define PAIRSEPARATOR ':'
# define SEPARATOR ','
# define ACTION_OBJECT_SEPARATOR ' '

/* actions */
# define CREATE "CREATE"
# define ADD "ADD"
# define SET "SET"
# define CHANGE "CHANGE"
# define SELECT "SELECT"
# define DELETE "DELETE"
# define IN "IN"
# define PRINT "PRINT"
# define DUMP "DUMP"
# define FLUSH "FLUSH"

/* objects */
# define DATABASE "DATABASE"
# define TABLE "TABLE"
# define COLUMN "COLUMN"
# define ROW "ROW"
# define RECORD "RECORD"
# define TYPE "TYPE"
# define DEBUG "DEBUG"

# define TABLELINE "+------------------------------------------------------+\n"

typedef enum boolean
{
	False,
	True
}			bool;

typedef struct			s_db
{
	char 				*name;
	int					amountTables;		// how many tables
	struct s_table		*firstTable;		// first table in DB
	struct s_table		*lastTable;			// last table in DB
	bool				error;				// any errors?
	char 				*nameError;			// name of error
	bool				debug;				// debug mode, print errors and log
}						t_db;

typedef struct			s_table
{
	char 				*nameTable;			// name of table
	size_t	 			amountColumns; 		// how many columns
	size_t	 			amountRecords; 		// how many records
	size_t	 			amountRows; 		// how many records (rows)
	bool				empty;				// is empty table? True/False
	struct s_column		*firstColumn;		// first column in Table
	struct s_column		*lastColumn;		// first column in Table
	struct s_table		*nextTable;			// next table in DB
}						t_table;

typedef struct			s_column
{
	char 				*nameColumn;		// name of column
	char 				*typeColumn;		// type of column
	size_t	 			amountRecords; 		// how many records
	struct s_record		*firstRow;			// first Record (in column)
	struct s_record		*lastRow;			// last Record (in column)
	struct s_column		*nextColumn;		// next Column (right)
}						t_column;

typedef struct			s_record
{
	bool				isID;				// is first record in row? True/False
	bool				empty;				// is empty record? True/False
	size_t				id;					// id record record (row uniq id)
	void 				*value;				// value of record (union?)

	char 				*typeRecord;		// type of record
	struct s_record		*right;				// pointer in table
	struct s_record		*left;
	struct s_record		*down;
	struct s_record		*up;

	struct s_column		*column;			// pointer to column
	struct s_record		*firstID;			// pointer to first record in row
}						t_record;

typedef struct 			s_query				// wrapper for query
{
	char				*action;
	char				*object;
	char				*tag;
	bool				lock;

	t_db 				**database;
	t_table				*table;
	t_column			*column;
	t_record			*row;
	void				*record;

	char				*nameDB;
	char				*nameTable;
	char				*nameColumn;
	char				*typeColumn;

	bool				memNameDB;			// 'mem' - is memory allocated?
	bool				memNameTable;		//
	bool				memNameColumn;		//
	bool				memTypeColumn;		//

	bool				error;				// True if error
	char				*error_name;

	struct s_query		*firstQuery;
	struct s_query		*next;
}						t_query;

void 					ft_db_parser(t_query **query, const char *format);
t_query					*ft_db_add_query(t_query *query, char *action, char *target, char *tag);
void					ft_db_null_query(t_query *query);
int	 					ft_db_action(t_query *query, va_list list);

void					ft_db_action_create(t_query *query, t_query *list);
void					ft_db_action_add(t_query *query, t_query *list);
void					ft_db_action_set(t_query *query, t_query *list);
void					ft_db_action_in(t_query *query, t_query *list);
void					ft_db_action_change(t_query *query, t_query *list);
void					ft_db_action_select(t_query *query, t_query *list);
void					ft_db_action_delete(t_query *query, t_query *list);
void					ft_db_action_print(t_query *query, t_query *list);
void					ft_db_action_dump(t_query *query, t_query *list);
void					ft_db_action_flush(t_query *query, t_query *list);

t_db					*ft_init_db(char *nameDB);
void					ft_set_error(t_db *database, char *nameError);
void					ft_clean_error(t_db *database);
void					ft_print_db_error(t_db *database);
void					ft_new_table(t_db *database, char *name);
t_table					*ft_return_table(t_db *database, char *name);
void					ft_new_table(t_db *database, char *name);
void 					ft_new_column(t_db *database, char *nameTable, char *nameColumn, char *typeColumn);
t_column				*ft_return_column(t_table *table, char *nameColumn);
int						ft_check_type_of_column(char *typeColumn);
void 					ft_new_record(t_db *database, char *tableName, char *nameColumn, char *type, void *record);
void					ft_create_row(t_db *database, t_table *table, t_column *column);
int 					ft_db(const char *restrict format, ...);

void					ft_print_debug_info(t_db *database, char *info);
void					ft_db_dump(t_db *database, char *file);
int 					ft_is_all_print(const char *str);
void					ft_db_print_all_db(t_db *database);
void					ft_print_columns(t_table *table, t_record **rows);
void					ft_print_table_specific(t_table *table);
void					ft_print_records(t_record *rows);
void					ft_print_record_specific(t_record *record);

void			ft_set_false_by_default_for_memory_allocation(t_query *query);

//void					ft_free_query_list(t_query *queryLock);
//t_query					*ft_add_query_to_free(t_query *queryLock, t_query *currentList);
//t_query					*ft_free_list_and_next(t_query *list);

#endif
