#include <const.h>

// Verb for dropping objects.

string query_action_name( mixed *action ) {
    return "Drop " + action[B_PARAM][0]->query_distant();
}

int main( string str ) {
    object env, *list;
    string a, b;
    int i;

    if( !str ) {
   notify_fail("Drop what?\n");
   return 0;
    }

    env = this_player();
    // A little weird to say 'drop the box from my bag' but I don't mind letting it work.
    if( sscanf(str, "%s from %s", a, b) ) {
   list = all_present( b, env );
   if( !list ) list = all_present( b );
   if( !list ) {
       notify_fail("I don't know what you mean by '"+b+"'.\n");
       return 0;
   }
   env = list[0];

   list = all_present( a, env );
    }
    else {
   list = all_present( str, env );
   if( !list ) list = all_present( str );
   if( !list ) {
       notify_fail("I don't know what you mean by '"+str+"'.\n");
       return 0;
   }
    }

   WALK_ACTION_PARAM( 500, list[0], list );

   return 1;
}

void on_action( object target, object *list ) {
   int i;
   int burdened = this_player()->query_held_weight() > this_player()->query_weight_capacity();
   object *dropped = ({ });
   for( i = 0; i < sizeof(list); i++ ) {
      if (!burdened &&
         sizeof(all_inventory(environment(this_player())))
         >= 100
      ) {
         /* unless it's a forced fumble, limit the number of objects
         in a room to 100.  Otherwise we get nsdf's from driver indigestion
         - gp */
         msg("This place is too cluttered for you to drop anything.");
         return;
      }
      int flag = 0;
      if( !burdened && list[i]->query_kept() ) {
         flag = 0;
      } else {
         flag=list[i]->on_drop( this_player() );
      }
      if (flag & MOVE_OK_FLAG) {
         list[i]->move( environment(this_player()) );
         if( list[i] )
         {
            list[i]->set_x( this_player()->query_x() );
            list[i]->set_y( this_player()->query_y() );
         }
      }
      if ((flag & MOVE_OK_FLAG) && !(flag & MOVE_SILENCE_FLAG)) {
         dropped += ({ list[i] });
      }
   }

   if( sizeof(dropped) ) {
      this_player()->msg_local("~CACT~Name ~verbdrop " + inventory_string(dropped) + ".~CDEF");
   } else {
      msg("It is impossible to drop that.");
   }
}
