#include <const.h>
#include <const/battconst.h>

string query_action_name( mixed * action ) {
   if ( !action[B_TARGET] )
      return "Abandon <target disappeared>";
   else
      return "Abandon " + action[B_TARGET]->query_distant();
}

int main( string param ) {
   object victim;

   if ( !param )
      return notify_fail( "What do you wish to abandon?\n" );

   victim = single_present( param, environment(this_player()) );
   if ( !victim )
      return notify_fail( "I have no idea what you're trying to abandon.\n" );

   if( !victim->query_is_building() )
      return notify_fail( "It is impossible to abandon that.\n" );

   if ( !(victim->query_owner() == this_player()->query_name()) )
      return notify_fail( "You cannot abandon something you don't own.\n" );

   WALK_ACTION( 1000, victim );
   return 1;
}

void on_action( object target ) {

   if ( target->query_owner() == this_player()->query_name() ) {
      target->set_owner(0);
      msg( "You abandon the building." );
   } else
      msg( "Somehow you have lost the claim you sought to abandon." );
}
