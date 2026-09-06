#include <ai_module.h>

// What part of the day we're in.
string preferred_room;

void routine() {
   switch( query_hour() ) {
      case 21..23:
      case 0..6:
         environment()->set_default_doing( "sleeping" );
         preferred_room = "start";
         break;
      case 7..11:
      case 13..19:
         environment()->set_default_doing( "playing" );
         preferred_room = "start";
         break;
      case 12:
      case 20:
         environment()->set_default_doing( "waiting for food" );
         preferred_room = "pantry";
         break;
   }
}

void setup() {
/*  Old descriptive texts... trying to fix these...
   environment()->set_short( "a child" );
   environment()->set_plural( "children" );
   environment()->set_look( "One of Walraven's recent arrivals, this child will certainly be seeking ~poss fortune someday." );
*/

   environment()->set_name( "child" );
   environment()->set_plural( "children" );
   environment()->set_distant( "a child" );
   environment()->set_specific( "the child" );
   environment()->set_look( "~Poss bright eyes gleaming with the innocence of youth beneath a mane of unruly hair; this human child is a bundle of potential. ~Pron will certainly be looking to make ~poss fortune one day, but for now, playing is ~poss only concern. ~Pron is $(HP)." );

   // We make them adults after 1 "year"
   //gp:  ok, 48 seconds in a mud hour?  yeah right
   //365 days in year, 24 hours in day, 3600 real seconds in hour
   //30 seconds in mud second, 120 mud seconds in hour
   environment()->set_env_var( "time_to_grow_up", time() + 120 * 24 * 365 );
   environment()->remove_ai_module( "worker" );
}

void grow_up() {
   // Become a worker (i.e. looking for work)
   environment()->use_ai_module( "worker" );
   // Stop being a kid
   destruct( this_object() );
}

ScriptBegin
   Script( "on_tick" )
      If( Myself->query_env_var("time_to_grow_up") < time() ) Do
         Lpc( call_out("grow_up", 0) )
         Abort
      End
      If( !at_home() )
         Abort
      Lpc( routine() );
      If( my_room() != home_room(preferred_room) )
      Do
         MoveTo( home_room(preferred_room) );
         Com( "walk random" );
      End
   End
   Script( "on_hunger" )
      MoveTo( home_room("pantry") )
      Get( find_food(present("larder", home_room("pantry"))) )
      Lpc( eat_food_in_inventory() );
      Put( find_food(Myself), present("larder", home_room("pantry")) )
   End
   // Cheat on thirst for now. Need to add wells or something.
   Script( "on_thirst" )
      Lpc( Myself->add_drink(50) );
   End
   Script( "on_talk" )
      If( Myself->query_default_doing() == "sleeping" )
         Abort
      Delay( 2 )
      If( HasKeyword(Message, "introduce") )
         Com( "introduce to " + Actor->query_name() )
   End
   Script( "on_offer" )
      If( Myself->query_default_doing() == "sleeping" )
         Abort
      If( sizeof(filter(Items, (: $1->query_is_edible() :))) == sizeof(Items) )
         Com( "accept" )
      Else
         Com( "reject" )
   End
End
