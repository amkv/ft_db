/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem Kalmykov <akalmyko@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:11:34 by akalmyko          #+#    #+#             */
/*   Updated: 2017/05/03 16:15:43 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_db alpha version 0.0.1 */

#ifndef DB_H
# define DB_H

# include "../lib/libft/libft.h"
# include <stdarg.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>

/* constants */
# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0
# define ISEQUAL 0
# define NONPRINTABLE 0
# define STRING 1
# define INT 2
# define PAIRSEPARATOR ':'					/* Separator for query <ACTION> <OBJECT> [:] <TAG>, */
# define SEPARATOR ','						/* Separator for query <ACTION> <OBJECT> : <TAG> [,] */
# define ACTION_OBJECT_SEPARATOR ' '		/* Separator for query <ACTION>[ ]<OBJECT> : <TAG>, */
# define TABLELINE "+------------------------------------------------------+\n"

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
# define TO "TO"

/* objects */
# define DATABASE "DATABASE"
# define TABLE "TABLE"
# define COLUMN "COLUMN"
# define ROW "ROW"
# define RECORD "RECORD"
# define TYPE "TYPE"
# define DEBUG "DEBUG"

typedef enum boolean
{
	False,
	True
}			bool;

typedef struct			s_db
{
	char 				*name;				/* name of BD */
	int					amountTables;		/* how many tables */
	struct s_table		*firstTable;		/* first table in DB */
	struct s_table		*lastTable;			/* last table in DB */ 
	bool				error;				/* any errors? */
	char 				*nameError;			/* name of error */
	bool				debug;				/* debug mode, print errors and log */
	bool				unused;				/* flag for colmpiler (not actualy using in program) */
}						t_db;

typedef struct			s_table
{
	char 				*nameTable;			/* name of table */
	size_t	 			amountColumns; 		/* how many columns */
	size_t	 			amountRecords; 		/* how many records */
	size_t	 			amountRows; 		/* how many records (rows) */
	bool				empty;				/* is empty table? True/False */
	struct s_column		*firstColumn;		/* first column in Table */
	struct s_column		*lastColumn;		/* first column in Table */
	struct s_table		*nextTable;			/* next table in DB */
	bool				unused;				/* flag for colmpiler (not actualy using in program) */
}						t_table;

typedef struct			s_column
{
	char 				*nameColumn;		/* name of column */
	char 				*typeColumn;		/* type of column */
	size_t	 			amountRecords; 		/* how many records */
	bool				unused;				/* flag for colmpiler (not actualy using in program) */
	struct s_record		*firstRow;			/* first Record (in column) */
	struct s_record		*lastRow;			/* last Record (in column) */
	struct s_column		*nextColumn;		/* next Column (right) */

}						t_column;

typedef struct			s_record
{
	bool				isID;				/* is first record in row? True/False */
	bool				empty;				/* is empty record? True/False */
	size_t				id;					/* id record record (row uniq id) */
	void 				*value;				/* value of record (union?) */
	bool				unused;				/* flag for colmpiler (not actualy using in program) */
	char 				*typeRecord;		/* type of record */
	struct s_record		*right;				/* pointer in table */
	struct s_record		*left;				/* pointer in table */
	struct s_record		*down;				/* pointer in table */
	struct s_record		*up;				/* pointer in table */
	struct s_column		*column;			/* pointer to column */
	struct s_record		*firstID;			/* pointer to first record in row */
}						t_record;

typedef struct 			s_query				/* wrapper for query */
{
	char				*action;			/* string from query parser */
	char				*object;			/* string from query parser */
	char				*tag;				/* string from query parser */
	bool				lock;				/* True if composite query */
	t_db 				**database;			/* pointer to DB */
	t_table				*table;				/* pointer to Table */
	t_column			*column;			/* pointer to Column */
	t_record			*row;				/* pointer to first element in the row */
	void				*record;			/* pointer to Record */
	char				*nameDB;			/* string name of DB (memory allocated) */
	char				*nameTable;			/* string name of Table (memory allocated) */
	char				*nameColumn;		/* string name of Column (memory allocated) */
	char				*typeColumn;		/* string type of Column or Record(memory allocated) */
	char				*nameDBTo;			/* string name of TO DB (memory allocated) */
	char				*nameTableTo;		/* string name of TO Table (memory allocated) */
	char				*nameColumnTo;		/* string name of TO Column (memory allocated) */
	char 				*nameRecordTo;		/* string name of TO Record (memory allocated) */
	size_t				numRowTo;			/* number or row */
	char				*typeColumnTo;		/* string name of TO typeColumn (memory allocated) */
	bool				memNameDB;			/* 'mem' - is memory allocated? */
	bool				memNameTable;		/* memory allocated? */
	bool				memNameColumn;		/* memory allocated? */
	bool				memTypeColumn;		/* memory allocated? */
	bool				memNameDBTo;		/* memory allocated? */
	bool				memNameTableTo;		/* memory allocated? */
	bool				memNameColumnTo;	/* memory allocated? */
	bool				memNameRecordTo;	/* memory allocated? */
	bool				memTypeColumnTo;	/* memory allocated? */
	bool				error;				/* True if error */
	char				*error_name;		/* string error (static char*) */
	bool				unused;				/* flag for colmpiler (not actualy using in program) */
	struct s_query		*firstQuery;		/* pointer to first query in the query process (parser) */
	struct s_query		*next;				/* next query from parser */
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
void					ft_db_action_to(t_query *query, t_query *list);
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
t_record				*ft_return_record(t_column *column, char *typeRecord, void *value);
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
void					ft_set_false_by_default_for_memory_allocation(t_query *query);

#endif
