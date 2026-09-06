#include <battle.h>

int main( string param ) {
   object *list, ob, *inv = ({});
   string verb = query_verb()[2..];
   if ( verb == "move" ) // this happens if unhold was called by remove
      verb = "hold";

   if( !param ) {
      msg("What would you like to un"+verb+"?");
      return 1;
   }

   foreach ( ob : all_inventory(this_player()) )
      if (ob->query_held())
         inv += ({ob});

   if (!sizeof(inv)) {
      msg("You aren't "+verb+"ing anything!");
      return 1;
   }

   list = all_present( param, this_player(), all_inventory(this_player()) - inv );

   if( !list ) {
      if (all_present(param, this_player()))
        msg("You aren't "+verb+"ing that!");
      else
        msg("I don't see anything on you that matches '" + param + "'");
      return 1;
   }

   foreach( ob: list ) {
      if (ob->query_weapon())
         verb = "wield";
      else
         verb = "hold";
      if( environment(ob) != this_player() )
         list -= ({ ob });
      else if (ob->query_cursed()) {
         msg("You can't stop "+verb+"ing "+ob->query_specific()+", it appears to be cursed!");
         list -= ({ ob });
      } else
         ob->set_held(0);
   }

   if (sizeof(list))
      this_player()->msg_local("~CACT~Name ~verbstop "+verb+"ing "+inventory_string(list)+".~CDEF");

   this_player()->recalc();
   this_player()->adopt_best_form();

   return 1;
}
