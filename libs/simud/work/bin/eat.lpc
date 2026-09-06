/**
 * The original version of the 'eat' verb was written ages ago by myself,
 * and was then re-written by Acius shortly thereafter. Much time has
 * passed and the ugly code not only warrants some cleanup, it needs a good
 * bit of healing - changes in the way food works have not ever been
 * dealt with.
 *
 * Thus... I now attempt a 'rewrite' of the stupid command... wish me luck.
 * - Al  [Dec 21, '05]
 */

#include <const.h>

string query_action_name() {
   return "Eat";
}

// Values for ate_something:
// 0: Nothing eaten, no errors
#define ERR_NO_ERROR   0
// -1: Nothing eat, but something could have been drunk
//     ALSO used the other way aroun if we used 'drink' but coul have eaten
#define ERR_DRINKABLE   -1
// -2: Nothing eat, not edible (not consumable)
#define ERR_NOT_EDIBLE   -2
// -3: Nothing eaten, too full to eat
#define ERR_TOO_FULL   -3
// -4: Nothing eaten, object was not in inventory
#define ERR_NOT_HERE   -4
// 1: Something eaten
#define ERR_ATE_STUFF   1
// 2: Something eaten, but ran out of room before all things could be eaten
#define ERR_ATE_FULL   2

int main(string str) {
   object env, *list, *inv_list, ob;
   string a, b;

   // set this to true if the command is 'eat' otherwise, assume we are
   // drinking - the same code is to be used for both commands, drink just
   // inherits this file
   int eating = (query_verb() == "eat");
   inv_list = ({ });

   if( this_player()->query_dead() ) {
      notify_fail( "You're dead, you can't "+query_verb()+"!\n" );
      return 0;
   }

   if( !str ) {
      notify_fail( capitalize(query_verb()) + " what?\n");
      return 0;
   }

   /** All of this craziness is intended to locate the exact item (or
    * items) we are trying to eat. The block of code is borrowed directly
    * from the get/drop commands.
    */

   env = this_player();
   if( sscanf(str, "%s from %s", a, b) ) {
      list = all_present(b,env);
      if( !list ) list = all_present( b, environment(this_player()) );
      if( !list ) {
         notify_fail( "I don't know what you mean by " + b + ".\n" );
         return 0;
      }
      env = list[0];
      list = all_present( a, env );
   }
   else {
      list = all_present( str, this_player() );
      if( !list )
         list = all_present(str, environment(this_player()));
      if( !list && sscanf(str, "from %s", str) ) {
         list = all_present( str, this_player() );
         if( !list ) list = all_present(str, environment(this_player()));
      }
      if( !list ) {
         notify_fail("I don't know what you mean by "+str+".\n");
         return 0;
      }
   }

   if ( !list )
      return notify_fail("I don't know what you mean by that.");

   foreach( ob : list ) {
      ob->set_player_lock( this_player() );

      if( member(all_environment(ob), this_player()) >= 0 ) {
         inv_list += ({ ob });
         list -= ({ ob });
      }
   }

   if( sizeof( inv_list ) != 0 )
      this_player()->push_action( ({ 1000, this_object(), this_player(), ST_SITTING | ST_STANDING | ST_LYING | ST_CROUCHING, ({ inv_list, eating }) }) );
   if( sizeof( list ) != 0 )
      WALK_ACTION_PARAM( 1000, list[0], ({ list, eating }) );
   return 1;
}

void on_action( object target, mixed list ) {
   int ate_something, x;
   string verb;

   int old_food = this_player()->query_food();
   int old_drink = this_player()->query_drink();

   // params are of the form ({ food array, eating boolean })
   int eating = list[1];
   list = list[0];

   ate_something = ERR_NO_ERROR;
   // actual stuff to do with eating starts here...
   for (x = 0; x < sizeof(list); x++) {
      if( !this_player()->query_touchable(list[x]) ) {
         if( ate_something == ERR_NO_ERROR ) ate_something = ERR_NOT_HERE;
         continue;
      }

      // are we eating or drinking?
      if( eating ) {
         if( !list[x]->query_is_edible() ) {
            if( list[x]->query_is_drinkable() &&
                ate_something <= ERR_NO_ERROR )
               ate_something = ERR_DRINKABLE;
            else if( sizeof(list) == ERR_ATE_STUFF &&
                     ate_something == ERR_NO_ERROR )
               ate_something = ERR_NOT_EDIBLE;
            continue;
         }
         if( this_player()->query_food() >= this_player()->query_food_capacity() ) {
            if( ate_something <= ERR_NO_ERROR )
               ate_something = ERR_TOO_FULL;
            else
               ate_something = ERR_ATE_FULL;
            break;
         }
         if( list[x]->on_consume(this_player()->query_food_capacity() - this_player()->query_food()) )
            ate_something = ERR_ATE_STUFF;
      } else {
      // we are drinking, same logic only backwardsish
         if( !list[x]->query_is_drinkable() ) {
            if( list[x]->query_is_edible() &&
                ate_something <= ERR_NO_ERROR )
               ate_something = ERR_DRINKABLE;
            else if( sizeof(list) == ERR_ATE_STUFF &&
                     ate_something == ERR_NO_ERROR )
               ate_something = ERR_NOT_EDIBLE;
            continue;
         }
         if( this_player()->query_drink() >= this_player()->query_drink_capacity() ) {
            if( ate_something <= ERR_NO_ERROR )
               ate_something = ERR_TOO_FULL;
            else
               ate_something = ERR_ATE_FULL;
            break;
         }
         if( list[x]->on_consume(this_player()->query_drink_capacity() - this_player()->query_drink()) )
            ate_something = ERR_ATE_STUFF;
      } // end: if eating/drinking
   } // end: for each item in list

   // messaging
   if( eating ) verb = "eat"; else verb = "drink";

   switch( ate_something ) {
      case ERR_DRINKABLE:
         msg("You can't "+verb+" that, but you might try "+
             (eating?"drink":"eat")+"ing it...");
         break;
      case ERR_NOT_EDIBLE:
         msg("You can't "+verb+" that!");
         break;
      case ERR_ATE_FULL:
      case ERR_TOO_FULL:
         msg("You can't bring yourself to "+verb+" another "+(lower_case(verb)=="eat"?"bite":"drop")+"!");
         break;
      case ERR_NOT_HERE:
         msg( "You are too far away from it to "+verb+" it." );
         break;
      case ERR_NO_ERROR:
         msg("Trying to "+verb+" that didn't work.");
         break;
      default:
         if( this_player()->query_is_player() ) {
/*
            debug( this_player()->query_name() + ": " +
                 (this_player()->query_food() - old_food) + " food, " +
                 (this_player()->query_drink() - old_drink) + " drink" );
*/
         }
   }

}
