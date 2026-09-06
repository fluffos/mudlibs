#include <inven.h>
#include <object.h>

int logoff_time;
mapping craft_time = ([ ]);
symbol *craft_order;

int on_get() {
   return MOVE_OK_FLAG;
}

string query_name() {
   return "_offline_box";
}

object id( string param ) {
   if( param == query_name() )
      return this_object();
   return 0;
}

void set_craft_time( mixed ob, int x ) {
   symbol obref;

   if( mappingp(ob) ) {
      craft_time = ob;
      return;
   }

   obref = to_objectref( ob );
   craft_time[obref] = x;
   if( member(craft_order, obref) < 0 ) craft_order += ({ obref });
}

mixed query_craft_time( mixed ob ) {
   if( !ob ) return craft_time;
   if( stringp(ob) ) ob = present(ob);
   return craft_time[to_objectref(ob)];
}

void on_suspend() {
   logoff_time = time();
}

void on_restore() {
   symbol iob;
   int time_elapsed;
   int obtime;
   object ob, *oblist = ({ }), partial;

   time_elapsed = time() - logoff_time;
   partial = 0;
   foreach( iob, obtime : craft_time ) {
      if( time_elapsed >= obtime ) {
         craft_time -= ([ iob ]);
         ob = find_objectref( iob );
         if( !ob ) {
            debug(as_lpc(iob) + " disappeared.");
            continue;
         }
         oblist += ({ ob });
         ob->move( environment() );
         time_elapsed -= obtime;
      }
      else if( time_elapsed > 0 ) {
         craft_time[iob] -= time_elapsed;
         time_elapsed = 0;
      }
   }
   if( sizeof(oblist) )
      msg( "~CBRTYou finished crafting " + inventory_string(oblist) + ".~CDEF" );
   if( partial )
      msg( "~CBRTYou did some work on " + partial->query_distant() + ", but haven't finished it yet.~CDEF");

   if( sizeof(craft_time) == 0 )
      destruct( this_object() );
}
