#include "path.h"
inherit "/std/outside";
string *monlist = ({"cat","mongrel","rat"});
create()
{
   int i;
   ::create();
    add_property("no_undead",1);
    set_light(LIGHT);
    set_short("Isle of Havmand: Track.");
    set_night_long("\nIsle of Havmand : Track\n\n"
    "   The tall dark wall of the castle looms above you on one side and "
    "tall dark trees loom above you on the other. It is impossible to "
    "see anything very clearly. "
    "\n\n");
    add_item(({"wall","castle","castle wall"}),"A huge castle wall looms to "
    "the west completely dominating the little village nestled against it. "
    "It is made of dark grey stone and towers almost to the sky."
    "\n");
    add_item(({"shack","hovel"}),"Grotty little buildings where the local "
    "peasantry live. They are nestled against the castle wall for protection "
    "and are generally in need of repair.\n");
    add_item(({"dirt","dust"}),"Brown, gritty dirt and dust gets scuffed up "
    "from the track and works its way into your clothing. It is very itchy.\n");
    add_item("ruts","Carts and wagons have been pulled along this road in the "
    "past, leaving deep ruts in the ground. There is no sign of them now, "
    "however.\n");
    add_feel("grit","Small coarse bits of dirt that get into your clothes "
    "making you itch and long for a hot bath somewhere.\n");
    add_item("jungle","A tangle of trees looming above you. Most of it seems "
    "so overgrown and impenetrable that it would be almost impossible to "
    "make any sort of path through it.\n");
    add_property("no_undead",1);

   for(i = 0; i <= TRACK_ANIMAL_MAX; i++)
   {
   add_clone(CHARS+monlist[random(sizeof(monlist))],1);
   }

   this_object()->reset();
}
/* Taniwha 1997 and REALLY REALLY pissed off, leave the %^^%^^& 
   dummy function HERE
*/
int dummy() { return 1; }
