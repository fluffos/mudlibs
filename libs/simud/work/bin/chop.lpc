#include <const.h>
#include <const/battconst.h>

string query_action_name( mixed * action ) {
   if( !action[B_TARGET] )
      return "Chop <target disappeared>";
   else
      return "Chop " + action[B_TARGET]->query_distant();
}

string do_chop(object victim)
{
   if( victim->query_size() < 5 )
      return "It's too small to chop down, really. Perhaps you'd like to uproot it?\n";

   WALK_ACTION( 1000, victim );
   return 0;
}

int main( string param ) {
   object victim;

   if( !param )
      return notify_fail("Just chop in general, or do you have something specific in mind?\n");

   victim = single_present( param, environment(this_player()), (: $1->query_is_plant() :) );
   if( !victim )
      victim = single_present( param, environment(this_player()) );

   if( !victim )
      return notify_fail("I have no idea what you're trying to chop.\n");

   if( !victim->query_is_plant() )
      return notify_fail("That's not something for chopping down, Lizzie.\n");

   string err = do_chop(victim);

   if (err) {
      return notify_fail(err);
   }

   return 1;
}

void on_action( object target ) {
   object weap;

   if( !target || environment(target) != environment(this_player()) ) return;

   foreach( weap: all_inventory(this_player()) )
   if( weap->query_held() && target->on_chop(weap) ) {
      this_player()->add_stat_use( "str", 5 );
      if( target )
         WALK_ACTION( 1000, target );
      return;
   }

   msg("You don't seem to be wielding anything with which to chop it...");
}
