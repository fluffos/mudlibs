#include <object.h>
#include <saveload.h>
#include <const.h>

nosave int count = 0;
nosave int random_threshold = random( 61 ) + 60;
string *messages;

void init() {
   ::init();

   if( sizeof( messages ) > 0 )
      set_heart_beat(1);
}

void create() {
   ::create();
   set_heart_beat(0);
   messages = ({  });
}

string query_name() { return "noise"; }
void set_messages( string *msg ) { if( sizeof( msg ) > 0 ) { messages = msg; set_heart_beat(1); } else set_heart_beat(0); }
string query_random_message() { if( sizeof( messages ) > 0 ) return messages[ random( sizeof( messages ) ) ]; else return 0; }
string* query_messages() { return messages; }
void add_message( string msg ) { if( !msg ) return; messages += ({ msg }); set_heart_beat(1); }
int id( string str ) { return str == "noise"; }

void heart_beat() {
   object ob;
   string msg;
   int players;
   count++;

   if( count == random_threshold ) {
      count = 0;
      players = 0;
      random_threshold = random( 61 ) + 60;
      msg = query_random_message();

      if( msg ) {
         foreach( ob : all_inventory( environment( this_object() ) ) ) {
            if( ob->query_is_player() ) {
               players++;
               msg_object( ob, msg );
            }
          }
       }
       else
          set_heart_beat(0);

       if( !players )
          set_heart_beat(0);
   }
}
