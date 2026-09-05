/**
 * Common functions for SQL clients.
 *
 * @author devo@eotl
 * @alias SqlLib
 */
#pragma no_clone
#include <sys/lpctypes.h>
#include <sql.h>

private inherit JSONLib;

protected string encode_value(mixed value);
protected string get_insert_statement(string table, mapping data, 
                                      mixed *params);
protected string get_update_statement(string table, mixed id, mapping data, 
                                      mixed *params);
protected string get_select_statement(string table, mapping key, 
                                      mixed *params);
protected string get_create_table_statement(string table, mapping *cols);
protected string get_table_info_statement(string table);

/**
 * Encode an LPC value for insertion into a SQL statement. Complex data types
 * are not currently supported.
 * 
 * @param  value         the value to encode
 * @return the encoded string
 */
protected string encode_value(mixed value) {
  switch (typeof(value)) {
    case T_NUMBER:
      return to_string(value);
    case T_STRING:             
      return sprintf("'%s'", implode(explode(value, "'"), "''"));
    case T_FLOAT:
      return to_string(value);
    case T_POINTER:
    case T_OBJECT:
    case T_MAPPING:
    case T_CLOSURE:
    case T_SYMBOL:
    case T_QUOTED_ARRAY:
    case T_STRUCT:
    default: 
      return "NULL";
  }
  return 0;
}

/**
 * Get an insert statement for inserting a single record into the specified
 * table. For parameterized statements, an empty array of parameters can be
 * passed by reference and it will be populated with the correct values when
 * the function returns. 
 * 
 * @param  table         the table name
 * @param  data          a mapping of column names to values
 * @param  params        a parameter array to populate, passed by reference
 * @return the insert statement for the provided data
 */
protected string get_insert_statement(string table, mapping data, 
                                      mixed *params) {
  string *columns = m_indices(data);
  params = m_values(data);
  string query;
  if (referencep(&params)) {
    query = sprintf("insert into %s (%s) values (%s);", 
                    table, 
                    implode(columns, ","), 
                    implode(map(params, (: "?" :)), ","));
  } else {
    query = sprintf("insert into %s (%s) values (%s);",
                    table,
                    implode(columns, ","),
                    implode(map(params, #'encode_value), ",")); //'
  }
  return query;
}

/**
 * Get an update statement for updatinging a single record in the specified
 * table. The update must be constrained on the id column, with the provided
 * id value. For parameterized statements, an empty array of parameters can be
 * passed by reference and it will be populated with the correct values when
 * the function returns. 
 * 
 * @param  table         the table name
 * @param  id            the row's id column value
 * @param  data          a mapping of column names to values
 * @param  params        a parameter array to populate, passed by reference
 * @return the update statement for the provided data
 */
protected string get_update_statement(string table, mixed id, mapping data, 
                                      mixed *params) {
  string *columns = m_indices(data);
  params = m_values(data);
  string query;
  if (referencep(&params)) {
    string set = "";
    for (int i = 0, int j = sizeof(columns); i < j; i++) {
      set = sprintf("%s%s=?,", set, columns[i]);
    }
    set[<1] = 0; // remove trailing comma
    query = sprintf("update %s set %s where %s=?;", 
                    table, 
                    set,
                    SQL_ID_COLUMN);
    params += ({ id });
  } else {
    string set = "";
    for (int i = 0, int j = sizeof(columns); i < j; i++) {
      set = sprintf("%s%s=%s,", set, columns[i], encode_value(params[i]));
    }
    set[<1] = 0; // remove trailing comma
    query = sprintf("update %s set %s where %s=%s;", 
                    table, 
                    set,
                    SQL_ID_COLUMN,
                    encode_value(id));
  }
  return query;
}

/**
 * Get a select statement to query for one or more records from the specified
 * table. All columns will be selected, but the result will be constrained by
 * a WHERE statement based on the provided key. The key is a mapping of
 * column names to values which will be AND'd together. For parameterized 
 * statements, an empty array of parameters can be passed by reference and it 
 * will be populated with the correct values when the function returns.  
 * 
 * @param  table         the table name
 * @param  key           a mapping of column names to values
 * @param  params        a parameter array to populate, passed by reference
 * @return the select statement for the provided key
 */
protected string get_select_statement(string table, mapping key, 
                                      mixed *params) {
  string *columns = m_indices(key);
  params = m_values(key);
  string where = "";
  if (referencep(&params)) {
    for (int i = 0, int j = sizeof(columns); i < j; i++) {
      where = sprintf("%s%s=? and ", where, columns[i]);
    }
    where[<5] = 0; // remove trailing 'and'
  } else {
    for (int i = 0, int j = sizeof(columns); i < j; i++) {
      where = sprintf("%s%s=%s and ", 
                      where, columns[i], encode_value(params[i]));
    }
    where[<5] = 0; // remove trailing 'and'
  }
  string query = sprintf("select * from %s where %s;", table, where);
  return query;
}

/**
 * Get a create table statement used to duh, create a table. The column list
 * needs to include info on type, defaults, indexes and constraints. 
 * 
 * @param  table         the table name
 * @param  cols          the column list containing type, flags, and default
 * @return the create table statement for the provided columns
 */
protected string get_create_table_statement(string table, mapping *cols) {
  string columns = "";
  int first = 1;
  foreach (mapping col : cols) {
    string type;
    switch (col[SQL_COL_TYPE]) {
      case SQL_TYPE_INTEGER:  type = "integer"; break;
      case SQL_TYPE_REAL:     type = "real";    break;
      case SQL_TYPE_TEXT:     type = "text";    break;
      case SQL_TYPE_BLOB:     type = "blob";    break;
      case SQL_TYPE_NULL:     
      default:                type = "null";    break;
    }
    string constraint = "";
    if (col[SQL_COL_FLAGS] & SQL_FLAG_PRIMARY_KEY) {
      constraint += "primary key ";
      if (col[SQL_COL_FLAGS] & SQL_FLAG_AUTOINCREMENT) {
        constraint += "autoincrement ";
      }
    } else if (col[SQL_COL_FLAGS] & SQL_FLAG_UNIQUE) {
      constraint += "unique ";
    }
    if (col[SQL_COL_FLAGS] & SQL_FLAG_NOT_NULL) {
      constraint += "not null ";
    }
    if (member(col, SQL_COL_DEFAULT)) {
      constraint += sprintf("default %s ", encode_value(col[SQL_COL_DEFAULT]));
    }
    columns = sprintf("%s%s%s %s %s", 
                      columns, 
                      (first ? "" : ", "),
                      col[SQL_COL_NAME], type, constraint);
    first = 0;
  }
  string query = sprintf("create table %s (\n %s );", table, columns);
  return query;
}

/**
 * Get a table info table statement.
 * 
 * @param  table         the table name
 * @return the table info statement
 */
protected string get_table_info_statement(string table) {
  return sprintf("pragma table_info(%s);", table);
}
