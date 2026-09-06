#include <ai_module.h>

void setup() {
   environment()->set_short( "a guard" );
   environment()->set_plural( "guards" );
   environment()->set_look( "A town guard that protects the town from attack." );
   environment()->set_default_doing( "looking watchful" );
}

ScriptBegin
   Script( "on_tick" )
   End
   Script( "on_hunger" )
      MoveTo( home_room("sleeping_quarters") )
      Get( find_food(present("larder", home_room("sleeping_quarters"))) )
      Lpc( eat_food_in_inventory() )
      Put( find_food(Myself), present("larder", home_room("sleeping_quarters")) )
   End
   // Still cheating on thirst.
   Script( "on_thirst" )
      Lpc( Myself->add_drink(50) )
   End
   Script( "on_talk" )
      If( HasKeyword(Message, "introduce") )
         Com( "introduce to " + Actor->query_name() )
   End
   Script( "on_offer" )
      If( sizeof(filter(Items, (: $1->query_is_edible() :))) == sizeof(Items) )
         Com( "accept" )
      Else
         Com( "reject" )
   End
End
