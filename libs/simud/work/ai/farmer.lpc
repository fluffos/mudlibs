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
         environment()->set_default_doing( "working in the garden" );
         preferred_room = "garden";
         break;
      case 12:
      case 20:
         environment()->set_default_doing( "preparing a meal" );
         preferred_room = "pantry";
         break;
   }
}

void setup() {
   environment()->set_short( "a farmer" );
   environment()->set_plural( "farmers" );
   environment()->set_look( "A peasant farmer who spends ~poss days working the soil." );
}

ScriptBegin
   Script( "on_tick" )
      If( !at_home() )
         Abort
      Lpc( routine() )
      If( my_room() != home_room(preferred_room) )
      Do
         MoveTo( home_room(preferred_room) )
         Com( "walk random" )
      End
   End
   Script( "on_hunger" )
      MoveTo( home_room("pantry") )
      Get( find_food(present("larder", home_room("pantry"))) )
      Lpc( eat_food_in_inventory() )
      Put( find_food(Myself), present("larder", home_room("pantry")) )
   End
   // Cheat on thirst for now. Need to add wells or something.
   Script( "on_thirst" )
      Lpc( Myself->add_drink(50) )
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
