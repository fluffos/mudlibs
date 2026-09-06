#include <const.h>

string query_action_name() {
   return "Skin";
}

int main( string param ) {
   object ob;

   return notify_fail( "Al has disabled this command. Try 'butcher'.\n" );

   if( !param )
      return notify_fail( "Skin what?\n" );

   if ( sizeof(filter( all_inventory(this_player()), (: HAS_ASPECT($1, C_KNIFE) || HAS_ASPECT($1, C_DAGGER) || HAS_ASPECT($1, C_DIRK) :) )) == 0 )
     return notify_fail("What, with your teeth? You need a dagger or knife.\n");

   ob = single_present( param, environment(this_player()),
      (: $1->query_dead() &&
         $1->query_env_var("skin_type") != "skinless" :) );

   if( !ob )
      ob = single_present( param, environment(this_player()) );
   if( !ob )
      return notify_fail( "Hrm, I can't seem to find that.\n" );

   if( !ob->query_dead() )
      return notify_fail( "It is customary to skin *dead* things you know....\n" );

   if( ob->query_env_var("skin_type") == "skinless" )
      return notify_fail( "Hrm, it appears to be skinless. Perhaps somebody already did the honors?\n" );

   WALK_ACTION( 1100, ob );

   return 1;
}

void on_action( object ob ) {
   object skin_ob;

   skin_ob = ob->on_skin();
   if( !skin_ob ) {
      msg( "Apparently, there's no way to skin that." );
      return;
   }

   skin_ob->move( this_player() );
   this_player()->msg_local( "~CACT~Name ~verbskin the " + skin_ob->query_name() + " from " + ob->query_specific() + ".~CDEF" );
   this_player()->add_readiness( -200 );
}
