/**
 * Lets objects make SQL queries. Mostly here to keep track of connection info.
 * 
 * @author devo@eotl
 * @alias SqlMixin
 */
#pragma no_clone
#include <sql.h>

private int enabled;
// TODO expand interface to support objects that use more than one db
private string database;

public void setup();
public void teardown();
int has_sql();
int set_database(string db);
string query_database();
protected varargs int insert(string table, mapping data, 
                             closure callback, varargs mixed *args);
protected varargs int update(string table, mapping data, 
                             closure callback, varargs mixed *args);
protected varargs int select(string table, mapping key, 
                             closure callback, varargs mixed *args);
protected varargs int create_table(string table, mapping *cols,
                                   closure callback, varargs mixed *args);
protected varargs int table_info(string table, 
                                 closure callback, varargs mixed *args);

/**
 * Setup the SQLMixin.
 */
public void setup() {
  load_object(SqlClientFactory);
  database = DEFAULT_DATABASE;
  enabled = 1;
}

/**
 * Tear down the SQLMixin.
 */
public void teardown() {
  enabled = 0;
}

/**
 * Return true to indicate this object is using a SQL connection.
 */
int has_sql() {
  return enabled;
}

/**
 * Set the database that will be used for running queries.
 * 
 * @param db the database connection string
 * @return 1 for success, 0 for failure
 */
int set_database(string db) {
  database = db;
  return 1;
}

/**
 * Get the database connection string.
 * 
 * @return the database connection string
 */
string query_database() {
  return database;
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
protected varargs int insert(string table, mapping data, 
                             closure callback, varargs mixed *args) {
  object sql_client = SqlClientFactory->get_client(database);
  sql_client->insert(
    table, 
    data, 
    (:
      // TODO add id to data in order to support sequences
      // sequence support needs some validation changes elsewhere in the code
      // $2[SQL_ID_COLUMN] = $1; 
      return apply($3, $2, $4); // call callback with data
    :), 
    data,
    callback, 
    args
  );
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
protected varargs int update(string table, mapping data, 
                             closure callback, varargs mixed *args) {
  if (!member(data, SQL_ID_COLUMN)) {
    return 0;
  }
  object sql_client = SqlClientFactory->get_client(database);
  sql_client->update(
    table, 
    (data - ([ SQL_ID_COLUMN ])),
    ([ SQL_ID_COLUMN : data[SQL_ID_COLUMN] ]), 
    (:
      apply($2, $1, $3)
    :), 
    callback, 
    args
  );
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
protected varargs int select(string table, mapping key, 
                             closure callback, varargs mixed *args) {
  object sql_client = SqlClientFactory->get_client(database);
  sql_client->select(
    table, 
    key,
    (:
      return apply($2, $1, $3);
    :), 
    callback, 
    args
  );
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
protected varargs int create_table(string table, mapping *cols,
                                   closure callback, varargs mixed *args) {
  object sql_client = SqlClientFactory->get_client(database);
  sql_client->create_table(
    table, 
    cols,
    (:
      return apply($2, $1, $3);
    :), 
    callback, 
    args
  );
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
protected varargs int table_info(string table, 
                                 closure callback, varargs mixed *args) {
  object sql_client = SqlClientFactory->get_client(database);
  sql_client->table_info(
    table, 
    (:
      return apply($2, $1, $3);
    :), 
    callback, 
    args
  );
  return 1;
}
