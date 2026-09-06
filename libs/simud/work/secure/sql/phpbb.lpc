#include <object.h>
#include <sql.h>

/** Connect to the MySQL database when the object is loaded.
 */
void create() {
   if( !sql_connect("phpBB") )
      debug("The phpBB interface doesn't work -- you probably haven't got phpBB installed.");
   ::create();
}

int query_category_id( string name ) {
   mixed ret;
   ret = request("select cat_id from categories where cat_title=\""+name+"\";");
   if( ret )
      return ret[0][0];
   return 0;
}

int query_forum_id( string name ) {
   mixed ret;
   ret = request("select forum_id from forums where forum_name=\""+name+"\";");
   if( ret )
      return ret[0][0];
   return 0;
}

mapping query_categories() {
   mixed res;
   mapping ret = ([ ]);
   int i;

   res = request("select cat_id, cat_title from categories;");
   if( !res ) return 0;
   // Convert to mapping
   for( i = sizeof(res); i--; )
      ret[res[i][1]] = to_int( res[i][0] );
   return ret;
}

mapping query_forums( int category ) {
   mixed res;
   mapping ret = ([ ]);
   int i;

   res = request("select forum_id, forum_name from forums where cat_id="+category+";");
   if( !res ) return 0;
   // Flatten it
   for( i = sizeof(res); i--; )
      ret[res[i][1]] = to_int( res[i][0] );
   return ret;
}

mapping query_topics( int forum ) {
   mixed res;
   mapping ret = ([ ]);
   int i;

   res = request("select topic_id, topic_title from topics where forum_id="+forum+";");
   if( !res ) return 0;
   // Flatten it
   for( i = sizeof(res); i--; )
      ret[res[i][1]] = to_int( res[i][0] );
   return ret;
}

string *query_posts( int topic ) {
   mixed res;

   res = request("select users.username, posts.post_time, posts_text.post_text from posts, posts_text, users where topic_id="+topic+" and posts.post_id = posts_text.post_id and users.user_id=posts.poster_id;");
   return res;
}

void create_new_topic( int forum_id, string topic_name, string message ) {
   int topic_id, post_id;

//   debug("Creating a topic currently disabled. Will work on it later.");
//   return;

   topic_name = safe_string(topic_name);
   message = safe_string(message);
   request( "insert into topics (topic_title, topic_poster, forum_id, topic_time) values ('"+topic_name+"', '-1', '"+forum_id+"', '"+sql_time()+"')" );

   topic_id = sql_insert_id();
   if( topic_id == 0 ) {
      debug("Failed to add topic! ("+db_error(sql_id)+")\n");
      return;
   }
   request( "insert into posts (topic_id, forum_id, poster_id, post_time, poster_ip) values ('"+topic_id+"', '"+forum_id+"', '-1', '"+sql_time()+"', '127.0.0.1')" );

   post_id = sql_insert_id();
   if( post_id == 0 ) {
      debug("Failed to add post! ("+db_error(sql_id)+")\n");
      return;
   }
   request( "insert into posts_text (post_id, post_text) values ("+post_id+", '"+message+"')" );
   request( "update topics set topic_last_post_id = "+post_id+" where topic_id = '"+topic_id+"'" );
   request( "update forums set forum_posts = forum_posts+1, forum_topics = forum_topics+1, forum_last_post_id = "+post_id+" WHERE forum_id = '"+forum_id+"'" );
}
