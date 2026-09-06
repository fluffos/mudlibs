#include <saveload.h>
#include <desc.h>
#include <object.h>
#include <reports.h>

string category, forum;
int topic_id;
nosave int cat_id, forum_id;

void create() {
   cat_id = forum_id = 0;
   name = "board";
   distant = "a message board";
   specific = "the message board";
}

void load_self( int id ) {
   ::load_self(id);
   if( category )
      cat_id = PHPBB->query_category_id( category );
   if( forum )
      forum_id = PHPBB->query_forum_id( forum );
}

int on_read( string param ) {
   int i;
   mixed messages;
   string curr_message;

   if( !topic_id ) {
      notify_fail("This board has not been linked to any data, so can't be read.\n");
      return 0;
   }
   messages = PHPBB->query_posts( topic_id );
   i = to_int(param);
   if( i < 1 || i > sizeof(messages) ) {
      notify_fail("No such message in this topic (There are "+sizeof(messages)+" message(s))\n");
      return 0;
   }
   else {
      curr_message = messages[--i][2];
      curr_message = regreplace(curr_message, "<[Ii][Mm][Gg].*>", ":-)", 1);
      curr_message = regreplace(curr_message, "<[Bb][Rr]>", "\n", 1);
      curr_message = implode( explode(curr_message, "&quot;"), "\"" );
      msg( "\n~CLABName~CDEF: "+messages[i][0]+"\n~CLABDate: ~CDEF"+messages[i][1]+"\n\n"+curr_message+"\n");
   }
   return 1;
}

void init() {
   add_action("on_read", "read");
   ::init();
}

void set_category( string name ) {
   cat_id = PHPBB->query_category_id( name );
   if( cat_id ) category = name;
   else category = 0;
}

void set_forum( string name ) {
   forum_id = 0;
   if( cat_id ) {
      forum_id = PHPBB->query_forum_id( name );
      if( forum_id ) forum = name;
   }
}

void set_topic( int id ) {
   topic_id = id;
}

int query_cat_id() {
   return cat_id;
}

int query_forum_id() {
   return forum_id;
}

int query_topic_id() {
   return topic_id;
}

string query_category() {
   return category;
}

mapping query_categories() {
   return PHPBB->query_categories();
}

mapping query_forums() {
   if( !category ) return 0;
   return PHPBB->query_forums( cat_id );
}

mapping query_topics() {
   if( !forum ) return 0;
   return PHPBB->query_topics( forum_id );
}

void create_new_topic( string topic_name, string message ) {
   PHPBB->create_new_topic( forum_id, topic_name, message );
}

string query_look() {
   return "This is a test bulletin board. Its current settings are:\nCategory: "+category+"\nForum: "+forum;
}