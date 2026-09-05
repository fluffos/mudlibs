/**
 * Client for interacting with SQLite databases.
 * 
 * @author devo@eotl
 * @alias SQLiteClient
 */
#include <sql.h>

private inherit SqlLib;

public void setup();
public int connect(string file);
public varargs int insert(string table, mapping data, 
                          closure callback, varargs mixed *args);
public varargs int update(string table, mapping data, 
                          closure callback, varargs mixed *args);
public varargs int select(string table, mapping key,
                          closure callback, varargs mixed *args);
public varargs int create_table(string table, mapping *cols,
                                closure callback, varargs mixed *args);
public varargs int table_info(string table, 
                              closure callback, varargs mixed *args);

/**
 * Setup the SQLiteClient.
 */
public void setup() {
}

/**
 * Connect client to database. This shouldn't need to be done more than once.
 * 
 * @param  file          sqlite database file
 * @return non-zero for success
 */
public int connect(string file) {
  return sl_open(file);
}

/**
 * Insert a new row into the database.
 * 
 * @param  table         table name
 * @param  data          mapping of column names to values for that column
 * @param  callback      callback to run upon successful insertion with result
 * @param  args          extra args for the callback
 * @return non-zero to indicate insert request was received
 */
public varargs int insert(string table, mapping data, 
                          closure callback, varargs mixed *args) {
  mixed *params;
  string query = get_insert_statement(table, data, &params);
  mixed result = apply(#'sl_exec, query, params); //'
  apply(callback, result, args);
  return 1;
}

/**
 * Update an existing row in the database.
 * 
 * @param  table         table name
 * @param  data          mapping of column names to values, id column value 
 *                       used for where clause
 * @param  callback      callback to run upon successful insertion with result
 * @param  args          extra args for the callback
 * @return non-zero to indicate update request was received
 */
public varargs int update(string table, mapping data, 
                          closure callback, varargs mixed *args) {
  if (!member(data, SQL_ID_COLUMN)) {
    return 0;
  }
  mixed id = data[SQL_ID_COLUMN];
  data -= ([ SQL_ID_COLUMN ]);

  mixed *params;
  string query = get_update_statement(table, id, data, &params);
  mixed result = apply(#'sl_exec, query, params); //'
  apply(callback, result, args);
  return 1;
}

/**
 * Select rows from a table.
 * 
 * @param  table         table name
 * @param  key           mapping of column names to values for where clause
 * @param  callback      callback to run upon successful query with result
 * @param  args          extra args for the callback
 * @return non-zero to indicate select request was received
 */
public varargs int select(string table, mapping key,
                          closure callback, varargs mixed *args) {
  mixed *params;
  string query = get_select_statement(table, key, &params);
  mixed result = apply(#'sl_exec, query, params); //'
  apply(callback, result, args);
  return 1;
}

/**
 * Create a new table.
 * 
 * @param  table         table name
 * @param  cols          an array of column data including column name, type,
 *                       and constraints
 * @param  callback      callback to run upon successful query with result
 * @param  args          extra args for the callback
 * @return non-zero to indicate create table request was received
 */
public varargs int create_table(string table, mapping *cols,
                                closure callback, varargs mixed *args) {
  string query = get_create_table_statement(table, cols);
  mixed result = apply(#'sl_exec, query); //'
  apply(callback, result, args);
  return 1;
}

/**
 * Get table info.
 * 
 * @param  table         table name
 * @param  callback      callback to run upon successful query with result
 * @param  args          extra args for the callback
 * @return non-zero to indicate table info request was received
 */
public varargs int table_info(string table, 
                              closure callback, varargs mixed *args) {
  string query = get_table_info_statement(table);
  mixed result = apply(#'sl_exec, query); //'
  apply(callback, result, args);
  return 1;
}

/**
 * Constructor.
 */
public void create() {
  setup();
}
