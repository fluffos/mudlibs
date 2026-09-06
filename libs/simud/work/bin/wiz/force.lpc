#include <const.h>

int main( string str ) {
   string pname, comm;
   object ob;

   if(this_player()->query_level() < WIZLEVEL) {
      msg("==> [Error] Access denied");
      return 0;
   }

   if(!str || sscanf(str, "%s %s", pname, comm) != 2) {
      msg("==> [Format] force player command");
      return 1;
   }

   ob = find_player(pname);
   if( !ob )  ob = find_living(pname);
   if(!ob) {
      msg("==> [Error] Could not find that player or creature.");
      return 1;
   }

   if(ob->query_level() < this_player()->query_level() || this_player()->query_level() >= ADMLEVEL ) {
      set_actor( this_player() );
      set_listener( ob );
      msg_object(ob, "~Name forces you to "+comm+".");
      msg("You force them to "+comm);
      ob->receive( "\n"+this_player()->query_specific()+" forces you to '"+comm+"':\n" );
      command(comm, ob);
      if( ob )
         ob->receive( ob->query_prompt() );
   } else {
      msg("==> [Error] Access denied.");
       set_actor( this_player() );
      set_listener( ob );
      msg_object(ob, "~CWRN~Name tried to force you to ~CCOM"+comm+"~CWRN.~CDEF");
      msg("~CWRNThey have been notified of your attempt.~CDEF");

   }

   return 1;
}
