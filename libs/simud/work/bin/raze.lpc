#include <const.h>
#include <const/battconst.h>

string query_action_name( mixed * action ) {
   if ( !action[B_TARGET] )
      return "Raze <target disappeared>";
   else
      return "Raze " + action[B_TARGET]->query_distant();
}

int main( string param ) {
   object victim;

   if ( !param )
      return notify_fail( "What do you wish to raze?\n" );

   victim = single_present( param, environment(this_player()) );
   if ( !victim )
      return notify_fail( "I have no idea what you're trying to raze.\n" );

   if( !victim->query_is_building() )
      return notify_fail( "It is impossible to raze that.\n" );

   if ( !victim->query_is_razable(this_player()) )
      return notify_fail( "You cannot raze something you don't own.\n" );

   WALK_ACTION( 1000, victim );
   return 1;
}

void on_action( object target ) {
   if ( !target->on_raze() )
      msg( "You can't raze that." );
}
