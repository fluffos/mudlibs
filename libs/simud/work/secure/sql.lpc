#include "/secure/sql_password"

#ifdef __MYSQL__

// The amount of time to wait before closing an inactive
// mySQL connection. This should be less than the server's
// timeout, or you could get bugs (the default server
// timeout is 28800 seconds, or 8 hours).

// The SQL object will disconnect when this amount of time
// has passed; it will automatically reconnect if any requests
// are made. Most SQL servers have a timeout, but if you set this
// value to be less than the server timeout you should be fine.
// If you set this to 0, it will never disconnect, but you will
// get bugs if there is a timeout on the server end (because
// the MUD does not know that it has been disconnected).
#define SQL_TIMEOUT (3600*1)

// Prototypes
mixed *request( string req );
int sql_disconnect();
int sql_connect( string db );
void sql_reconnect();
string sql_time( int seconds );
int sql_insert_id();
void sql_timeout();

int sql_id;
string db_name;

/** Debug query.
 */
string query_db_name() {
   return db_name;
}

/** Debug query.
 */
int query_sql_id() {
   return sql_id;
}

int sql_insert_id() {
   sql_reconnect();
   return db_insert_id( sql_id );
}

mixed *request( string req ) {
   mixed *result, data;

   //debug("Before reconnect: sql_id="+sql_id+", db_name="+db_name+".");
#if SQL_TIMEOUT
   remove_call_out( "sql_timeout" );
   call_out( "sql_timeout", SQL_TIMEOUT );
#endif
   sql_reconnect(); // If there was a timeout, reconnect.
   //debug("After reconnect: sql_id="+sql_id+", db_name="+db_name+".");
   if( !sql_id )
      return 0;
   if( db_exec(sql_id, req) != sql_id ) {
      debug("db_exec failed");
      return 0;
   }
   result = ({ });
   while( data = db_fetch(sql_id) ) result += ({ data });
   return result;
}

int sql_connect( string db ) {
   mixed res;

   //debug("sql_connect(\""+db+"\")");
   sql_disconnect();
   sql_id = db_connect(db, SQL_ACCOUNT, SQL_PASSWORD);
   db_name = db;
   // Raises an error on failure, so we can assume it worked.
   return 1;
//   res = db_exec( sql_id, "use " + db );
//   if( res == sql_id ) {
//      db_name = db;
//      return 1;
//   }
//   else
//      return 0;
}

void sql_reconnect() {
   //debug("sql_reconnect()");
   if( db_name && !sql_id )
      if( !sql_connect( db_name ) )
         raise_error("Failed to reconnect to database.\n");
}

int sql_disconnect() {
   //debug("sql_disconnect()");
   db_name = 0;
   if( sql_id )
   if( db_close( sql_id ) != sql_id ) {
      debug("Failed to close MySQL connection with ID "+sql_id);
      return 0;
   }
   sql_id = 0;
   return 1;
}

/** Closes the database connection. It will automagically reopen
 * if another request is made.
 */
void sql_timeout() {
   db_close( sql_id );
   sql_id = 0;
}

/** If this object is destructed, give back the connection id.
 */
string _destructor_sql() {
   sql_disconnect();
   return 0;
}

/** \return The full time of day in YYYY-MM-DD HH:MM format, appropriate for
 * SQL requests.
 *
 * \param seconds (Optional) The time you want. If 0, then the current time is given.
 */
varargs string sql_time( int seconds ) {
   string t, y;
   if( !seconds ) seconds = time();

   y = ctime( seconds )[20..];
   t = stime( seconds );
   return  y + "-" + t[3..4] + "-" + t[0..1] + " " + t[9..10] + ":" + t[12..13];
}

/** Escapes control codes, etc., in a string.
 */
string safe_string( string unsafe ) {
   unsafe = implode( explode(unsafe, "\\"), "\\\\" );
   unsafe = implode( explode(unsafe, "'"), "\\'" );
   unsafe = implode( explode(unsafe, "\""), "\\\"" );
   // want to allow newlines in post, but \r is cruft
   //unsafe = implode( explode(unsafe, "\n""), "\\n"" );
   unsafe = implode( explode(unsafe, "\r"), "" );
   //debug("need to get safe_string escaping everything");
   //unsafe = implode( explode(unsafe, "\x1a""), "\\x1a"" );
   //unsafe = implode( explode(unsafe, "\x00""), "\\x00"" );

   return unsafe;
}

#else

void _create_sql() {
   write("Unable to use MySQL; the driver does not have MySQL support compiled in.\n");
}

#endif
