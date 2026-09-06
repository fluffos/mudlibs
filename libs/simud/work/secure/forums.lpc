#include <object.h>
#include <sql.h>

// Constant(s)
#define ANONYMOUS_UID 1

/** Connect to the MySQL database when the object is loaded.
 */
void create() {
   if(!sql_connect("forums"))
      debug("The forums interface doesn't work -- this would be a bad thing.");
   ::create();
}

int query_forum_id(string name) {
   mixed ret;
  name = safe_string(name);
   ret = request("select fid from forums where forum_name='"+name+"';");
   if( ret )
      return ret[0][0];
   return 0;
}

mapping get_forums_by_level(int level) {
   mixed res;
   mapping ret = ([ ]);
   int i;

   res = request("select fid, name from forums where read_level<='"+level+"';");
   if(!res) { debug ("no res"); return 0;}
   // Flatten it
   for(i = sizeof(res); i--;)
      ret[res[i][1]] = to_int(res[i][0]);
   return ret;
}

int get_user_by_name( string name ) {
   mixed req;

   req = request( "select * from user where name = '"+name+"'" );
   if( sizeof(req) ) {
      return to_int(req[0][0]);
   }
   else {
      int new_uid;

      request( "insert into user (name) values ('"+name+"')" );
      new_uid = sql_insert_id();
      // The '1' is for normal-urgency log messages
      request( "INSERT INTO log (uid, level, message, at) VALUES ('" + new_uid + "', '1', '" + capitalize(name) + " posted from the MUD, thus creating their web account', NOW())" );
      return new_uid;
   }
   return ANONYMOUS_UID;
}

void lock_err() {
   request("UNLOCK TABLES");
   debug("Some terrible error happened, tables unlocked.");
}

varargs void create_new_thread( int fid, string location, string subject, string message, string user ) {
   mixed res;
   int post_id, comment_id, thread, uid;

   //debug("creating thread");

   if( user )
      uid = get_user_by_name( user );
   else if( this_player() )
      uid = get_user_by_name( this_player()->query_name() );
   else
      uid = ANONYMOUS_UID;

   location = safe_string(location);
   subject = safe_string(subject);
   message = safe_string(message);

   res = request("LOCK TABLES comment WRITE");
   if (res == 0) lock_err();

   res = request("SELECT MAX(thread) as mt FROM comment");
   if (res == 0) lock_err();
   thread = to_int(res[0][0]) + 1;

   res = request( "insert into comment (subject, body, posted, location, fid, uid, parent, thread, level, pos, col) VALUES ('"+subject+"', '"+message+"', NOW(), '"+location+"', '"+fid+"', "+uid+", 0, '"+thread+"', 0, 0, 'mud:"+sql_time()+"')" );
   if (res == 0) lock_err();

   comment_id = sql_insert_id();
   if( comment_id == 0 ) {
      debug("Failed to add post! ("+db_error(sql_id)+")\n");
      return;
   }
   request("UNLOCK TABLES");

   request( "INSERT INTO log (uid, level, message, at) VALUES ('" + uid + "', '1', 'started thread " + thread + "', NOW())" );
   request( "INSERT INTO log (uid, level, message, at) VALUES ('" + uid + "', '1', 'posted on thread " + thread + ", comment "+comment_id+": "+subject+"', NOW())" );
}
