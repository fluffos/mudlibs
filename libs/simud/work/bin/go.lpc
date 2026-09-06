#include <const.h>
#include <const/battconst.h>

int main( string param ) {
   if( !param && query_verb() == "go" ) {
      notify_fail("You run around in circles, like a dog chasing its tail. Then you stop.\n");
      return 0;
   }
   else if( !param && query_verb() != "go" ) {
      param = query_verb();
   }
   if( this_player()->query_dead() ) {
      return notify_fail("You're too stiff to move.\n");
   }
   if( this_player()->query_in_combat() ) {
      return notify_fail("You cannot just walk out of a fight!\n");
   }

   // Why do this? So that if you type a bunch of directions in a row,
   // like "n n n e e n" it'll queue them up properly. If you checked for
   // the existence of the exit in main(), it would look for the exits in
   // THIS room, not the room I'm going to be in after finishing the
   // rest of the action queue.
   this_player()->push_action( ({ 500, this_object(), this_player(), ST_STANDING, param }) );
   return 1;
}

void on_action( object target, mixed param ) {
   object exit_ob, old_env;
   int counter = 0;
   string ordinal, dir;

   if( this_player()->query_dead() ) {
      msg("You're too stiff to move.");
   }
   if( this_player()->query_in_combat() ) {
      msg("You cannot just walk out of a fight!");
     return;
   }

   if( sscanf(param, "%s %s", ordinal, dir) == 2 ) {
      counter = "/daemon/dictionary"->get_number_from_string( ordinal );
      if( counter < 0 ) param = dir;
      else counter = 0;
   }

   if( target != this_player() ) {
      // If you set the target of the action to the exit object, that'll work
      // as well. This is to make things like follow and flee easier to
      // implement.
      if( random(8) == 0 ) this_player()->add_stat_use( "spd", 1 );
      target->exit_action();
      return;
   }
   else {
      old_env = environment(this_player());
      foreach( exit_ob : filter( all_inventory(environment(this_player())), (: $1->query_is_exit() :) ) ) {
         if( exit_ob->query_name() == "exit_" + param ){
            counter++;
            if( counter >= 0 ) {
               if( random(20) == 0 ) this_player()->add_stat_use( "spd", 1 );
               exit_ob->exit_action();
               if( old_env == environment(this_player()) && sizeof(this_player()->query_actions()) )
                  msg("You start walking toward that exit.");
               return;
            }
         }
      }
   }
   msg("No such exit!");
}

string query_action_name( mixed *action ) {
   return "Go " + action[B_PARAM];
}
