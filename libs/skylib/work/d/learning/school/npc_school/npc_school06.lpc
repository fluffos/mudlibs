/*
* How to start building an interactive npc
* By Avelan, January '02
*/

#include "defs.h"
inherit ROOM_OBJ;
#define TESTNPC "/d/learning/school/characters/womble"
object womble;

void setup(){
    set_light(70);
    set_zone("npc_school");
    set_short("npc room");
    set_long("Well then, let's move on to the final"
      " stage of creating this npc.\nNow we shall make"
      " the npc respond to says and emotes.\nAlso we'll"
      " make it stun the player if he asks the womble to"
      " 'womble'.  It will show you how to use an effect.\n"
      "And finally, i think we should give the description of"
      " it some originality compared to other wombles, don't"
      " you think?\n");

    /*
    * Again, add_items here when doing a real room.
    */

    add_exit("forward",NPCSCHOOL+"npc_school07","path");
    add_exit("back", NPCSCHOOL+"npc_school05","path");

} /* setup() */

void reset(){
    if(!womble){
        womble = clone_object(TESTNPC);
        womble->move(TO,"$N wombles in from somewhere.");
    }
} /* reset() */
