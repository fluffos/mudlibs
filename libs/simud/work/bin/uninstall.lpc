#include <const.h>

void do_uninstall ( object where, object what, object ob );

int main ( string param ) {
   if ( !param )
      return notify_fail( "Uninstall what from where?\n" );

   string a;
   string b;

   if ( sscanf( param, "%s from %s", a, b ) != 2 )
      return notify_fail( "Uninstall what from where?\n" );

   object where = single_present( b, environment( this_player() ) );
   object what = single_present( a, where );

   if ( !where || !what )
      return notify_fail( "I cannot find that.\n" );

   object *keys = all_present( "key", this_player() );

   foreach ( object ob : keys ) {
      if ( ob->query_keycode() == what->query_keycode() ) {
         do_uninstall( where, what, ob );

         return 1;
      }
   }

   object *keyrings = all_present( "keyring", this_player() );

   foreach ( object ob : keyrings ) {
      object key;

      if ( key = ob->find_key( what->query_keycode() ) ) {
         do_uninstall( where, what, key );

         return 1;
      }
   }

   return notify_fail( "You do not possess the proper key.\n" );
}

void do_uninstall ( object where, object what, object ob ) {
   WALK_ACTION_PARAM( 1000, where, ({ what, ob }) );

   if ( sizeof( this_player()->query_actions() ) ) {
      set_target( where );
      msg( "You start walking toward ~targ." );
   }
}

string query_action_name( mixed *action ) {
   return "Uninstalling " + action[B_TARGET]->query_specific();
}

int on_action( object where, object *ob ) {
   object what = ob[0];
   object key = ob[1];

   if ( !what || !where )
      return notify_fail( "I cannot find that.\n" );

   if ( environment( key ) != this_player() )
      return notify_fail( "You do not possess the proper key.\n" );

   if ( !what->on_uninstall() )
      return notify_fail( "You cannot uninstall that.\n" );
}
