
#include "../cupelix.defs"
inherit "obj/monster";

void setup() {
   set_name("turtle");
   add_adjective("sea");
   add_adjective("giant");
   set_main_plural("giant sea turtles");
   add_plural("giant turtles");
   add_plural("turtles");
   set_short("giant sea turtle");
   set_long(
      "This is a giant sea turtle.  Many crustaceans have formed along " +
      "its body and shell.  Sea turtles are normally quiet and peaceful " +
      "but have been known to help fellow sea creatures in danger.\n");
   set_race("sea dweller");
   set_level(3);
   //add_attack("call", 0, 5, 10, 10, 10, "special");
   set_al(0);
}

object help;
string *creatures;

/*
int write_message(int dam,object him,object me,string type,string attack) {
   switch(attack) {
      case "call":
       if(sizeof(all_inventory(environment(obj()))) < 10)
       {
         creatures = ({ "sea_dolphin", "sea_snake",
                        "sea_turtle",  "sea_shark" });
         help = clone_object(MONSTER(creatures[random(sizeof(creatures))]));
         help->set_aggressive(1);
         help->move(environment(this_object()));
         write("The sea turtle flops around in the water and hits you with " +
            "a large fin.\n");
         say("The sea turtle flops around in the water.\n");
         say("A "+help->query_short()+" comes to help!\n");
       }
//     else
//       remove_attack("call");
         break;
      default:
         ::write_message(dam, him, me, type, attack);
         break;
   }
}
*/

