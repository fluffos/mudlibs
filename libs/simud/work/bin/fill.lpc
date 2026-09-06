#include <const.h>

string query_action_name( mixed * action ) {
   return "Fill " + action[B_PARAM]->query_name() + " from " + action[B_TARGET]->query_name();
}

int main( string param ) {
   string a, b;
   object jug, pond;

   if( !param || (sscanf(param, "%s from %s", a, b) != 2 && sscanf(param, "%s with %s", a, b) != 2) ) {
      notify_fail("What do you wish to fill, and from what?\n");
      return 0;
   }

   // I realized that 'jug' and 'pond' might be non-jug and non-pond
   // objects, but I figure this is readable :).
   jug = single_present( a, this_player() );
   if( !jug ) jug = single_present( a, environment(this_player()) );
   if( !jug ) {
     notify_fail("Sorry, I'm not sure what a '"+a+"' is.\n");
     return 0;
   }

   pond = single_present( b, environment(this_player()), all_inventory(jug) );

   if( !pond ) pond = single_present( b, this_player(), all_inventory(jug) );
   if( !pond ) {
     notify_fail("Sorry, I'm not sure what a '"+b+"' is.\n");
     return 0;
   }

   WALK_ACTION_PARAM( 1000, pond, jug );
   return 1;
}


void on_action( object pond, object jug ) {
   set_listener(this_player());
   set_target(jug);

   if( !this_player()->query_touchable(jug) )
      msg("You're not close enough to ~targ, so you can't fill ~objt.");
   else if( !jug->query_container() )
      msg("~Subt is not a container, so you can't fill ~objt.");
   else if( environment(pond) == jug )
      msg("You want to fill ~targ from itself?");
   else if( !pond->on_fill(jug) )
      msg("Didn't work. Either you did something stupid or I'm stupid. Either way, let's never speak of this again.");
}
