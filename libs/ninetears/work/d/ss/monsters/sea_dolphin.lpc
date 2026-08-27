
#include "../cupelix.defs"
inherit "obj/monster";

void setup() {
   set_name("dolphin");
   set_main_plural("dolphins");
   set_short("dolphin");
   set_long(
      "This normally docile dolphin seems rather excited about something.  " +
      "Its slippery skin and powerful body enables it to swim great " +
      "distances easily.  It is well known that dolphins may call upon " +
      "other creatures of the sea for help, and that they are more than " +
      "willing to respond to their companions' calls as well.\n");
   set_race("sea dweller");
   //add_attack("call", 0, 7, 10, 10, 10, "special");
   set_level(4);
   set_al(0);
}

/*


object help;
string *creatures;
int write_message(int dam,object him,object me,string type,string attack) {
   switch(attack) {
      case "call":
         if(sizeof(all_inventory(environment(obj()))) < 10) {
           creatures = ({ "sea_dolphin", "sea_snake",
                          "sea_turtle",  "sea_shark" });
           help = clone_object(MONSTER(creatures[random(sizeof(creatures))]));
           help->set_aggressive(1);
           help->move(environment(this_object()));
           write("The dolphin makes a loud squeaking noise and slaps you " +
            "in the face with its tail.\n");
           say("The dolphin makes a loud squeaking noise.\n");
           say("A "+help->query_short()+" comes to help!\n");
         }
         break;
      default:
         ::write_message(dam, him, me, type, attack);
         break;
   }
}

*/


