#include <const.h>
#include <const/battconst.h>

string query_action_name( mixed * action ) {
   if( !action[B_TARGET] )
      return "Uproot <target disappeared>";
   else
      return "Uproot " + action[B_TARGET]->query_distant();
}

int main( string param ) {
   object victim;

   if( !param ) {
      notify_fail("What do you wish to uproot?\n");
      return 0;
   }

   victim = single_present( param, environment(this_player()) );
   if( !victim ) {
      notify_fail("I have no idea what you're trying to uproot.\n");
      return 0;
   }
   if( victim->query_size() >= 5 ) {
      notify_fail("It's too big for you to handle. Perhaps an axe would come in handy.\n");
      return 0;
   }
   if( !victim->query_has_aspect(C_PLANT) ) {
      notify_fail("You can only uproot plants. It doesn't make sense for anything else.\n");
      return 0;
   }

   WALK_ACTION( 1000, victim );
   return 1;
}

void on_action( object target ) {
   object weap;

   if( !target ) return;

   this_player()->msg_local("~CACT~Name ~verbuproot ~targ.~CDEF");
   destruct(target);
}
