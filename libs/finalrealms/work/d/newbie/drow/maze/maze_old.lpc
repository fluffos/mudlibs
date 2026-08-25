inherit "/std/underground";
#include "path.h"

void setup() {

   set_light(15);

   set_short("Realm of the Drow:  The Great Maze");

   set_long("\n   Realm of the Drow:  The Great Maze.\n\n"
            "     You are in the great maze.  It is here that you shall "
            "learn your skills to survive in the underdark.  All who "
            "are under the level of five are welcome here to "
            "challenge their fate, and see if they have what it takes "
            "to become true Drow!"
            "\n\n");

   add_item(({"pillar"}),
            "  The pillar appears to be made out of the same grey stone "
            "as the walls.  Other than support, they don't appear to "
            "be of any importance.\n");

   add_smell("room", "It smells old.\n");
   add_taste("air", "The air tastes Musty and old.\n");

   add_exit("north", MAZE+"maze01", "corridor");
   add_exit("south", MAZE+"raiserm", "corridor");
   add_exit("east", MAZE+"guild", "corridor");
   add_exit("west","/d/bf/new_bf/BANEFALL/streets/bazaar03","door");
   //add_exit("west","/d/bf/banefall/city/bazaar3","door");
     modify_exit("west",({"function","mywest"}));

   add_property("no_undead",1);
}

int mywest()
{
object me;
int lv;
int xp;


me = this_player();
lv = (int)me->query_level();
xp = (int)me->query_xp();
if(lv < 5 ) {
   notify_fail("Cyrcia demands that you be her spectre of "
    "death for the captives in this prison till you have gained more "
     "experience.\n\n");
   return 0;
}
if(lv == 5&&xp > 30000) {
    write("Cyrcia laughs at your pitiful attempt to leave her "
       "maze with the experience of multiple captive slaughters.  This experience was meant to train you not "
     "for you to abuse.  You get no free ride here.\n\n");
   this_player()->adjust_xp(-xp+1000, this_player());
write_file("/d/bf/banefall/log/NEWBIES",this_player()->query_cap_name()+" had too much xp.\n");
return 1;
}
return 1;
}
