#include <const.h>

string query_action_name() {
   return "Pick";
}

int main( string param ) {
   string fruit_type, fruit_last_word, plant;
   object plant_ob;

   if( !param ) {
      notify_fail("You should try to pick <something> [from <something>].\n");
      return 0;
   }
   if( sscanf(param, "%s from %s", fruit_type, plant) != 2 ) {
      fruit_type = param;
      plant = "all";
   }

   fruit_last_word = fruit_type;
   do {
      plant_ob = single_present( plant,
         environment(this_player()),
         (: string ft = $1->query_fruit_type();
            return ft && ft->id(fruit_last_word) && $1->query_fruit(); :)
       // last condition added by al at 4 in the stupid morning on 8/17/04
       // in response to sora's request in thread 1906
      );
   } while( !plant_ob && sscanf(fruit_last_word, "%~s %s", fruit_last_word) == 2 );
   if( plant != "all" && !plant_ob ) plant_ob = single_present( plant, environment(this_player()) );
   // this statement also added at the time of the previous butchering
   if( !plant_ob ) {
      plant_ob = single_present( plant,
         environment(this_player()),
         (: string ft = $1->query_fruit_type();
            return ft && ft->id(fruit_type); :)
      );
   }
   if( !plant_ob ) {
      notify_fail("I don't understand what plant to pick it from.\n");
      return 0;
   }

   WALK_ACTION_PARAM(1000, plant_ob, fruit_type);
   return 1;
}

void on_action( object target, string fruit_type ) {
   int count = 1;

   if( sscanf(fruit_type, "%d %s", count, fruit_type) != 2 ) {
      string a, b;
      if( sscanf(fruit_type, "%s %s", a, b) == 2) {
         fruit_type = b;
         if( NUMBERS_MAP[a] != 0 ) {
            count = NUMBERS_MAP[a];
         }
         else if( a == "all" ) {
            count = target->query_fruit();
         }
         else {
            count = 1;
         }
      }
   }

   if( !target->on_pick(fruit_type, count) ) {
      set_target(target);
      msg("Trying to pick '"+fruit_type+"' from ~targ doesn't work.");
   }
}
