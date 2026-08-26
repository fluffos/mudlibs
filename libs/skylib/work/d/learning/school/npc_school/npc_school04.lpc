/*
* How to start building an interactive npc
* By Avelan, January '02
*/

#include "defs.h"
inherit ROOM_OBJ;
#define TESTNPC "/d/learning/school/characters/womble_basic"
object womble;

void setup(){
    set_light(70);
    set_zone("npc_school");
    set_short("npc room");
    set_long("Ok, let's say we want to build an interactive"
      " npc.  Where should we start?\nWell, i'd start with "
      "making a basic npc, like the one standing in the room"
      " right now.(You can do 'more womble' to see what's in "
      "the code.)\nLook through the code of the npc and when"
      " you're ready move on to the next room where we shall"
      " start adding more stuff to the same npc.\n");

    /*
    * Again, add_items here when doing a real room.
    */

    add_exit("forward",NPCSCHOOL+"npc_school05","path");
    add_exit("back", NPCSCHOOL+"npc_school03","path");

} /* setup() */

void reset(){
    if(!womble){
        womble = clone_object(TESTNPC);
        womble->move(TO,"$N wombles in from somewhere.");
    }
} /* reset() */
