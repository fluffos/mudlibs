#include <const.h>
#include <const/battconst.h>

string query_action_name( mixed * action ) {
   if ( !action[B_TARGET] )
      return "Claim <target disappeared>";
   else
      return "Claim " + action[B_TARGET]->query_distant();
}

int main( string param ) {
   object victim;

   if ( !param )
      return notify_fail( "What do you wish to claim?\n" );

   victim = single_present( param, environment(this_player()) );
   if ( !victim )
      return notify_fail( "I have no idea what you're trying to claim.\n" );

   if( !victim->query_is_building() )
      return notify_fail( "There is no concept of squatter's rights for that.\n" );

   if ( victim->query_owner() != 0 )
      return notify_fail( "Squatter's rights can only be claimed on abandoned buildings.\n" );

   WALK_ACTION( 1000, victim );
   return 1;
}

void on_action( object target ) {
   if ( target->query_owner() ) {
      msg( "Somehow the building you tried to claim is no longer abandoned." );
      return;
   }

   target->set_owner( this_player()->query_name() );
   msg( "You declare squatter's rights as you claim the building as your own." );
}
