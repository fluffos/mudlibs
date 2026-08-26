/*
* How to start building an interactive npc
* By Avelan, January '02
*/

#include "defs.h"
inherit ROOM_OBJ;
#define TESTNPC "/d/learning/school/characters/womble_interm"
object womble;

void setup(){
    set_light(70);
    set_zone("npc_school");
    set_short("npc room");
    set_long("Ok, now we have a basic npc set up. Next"
      " we shall add chats for it and also give it a weapon"
      " of some sort.  I'll give it one armour i've made myself"
      " and one weapon from the armoury.\nIf you want a list"
      " of all weapons available from the armoury, you can do"
      " 'exec return ARMOURY_H->query_weapons();', also, do"
      " 'help armoury' for more information about the armoury.\n"
      "You can go to the item school to see how to code your own"
      " weapons and armours.\n");

    /*
    * Again, add_items here when doing a real room.
    */

    add_exit("forward",NPCSCHOOL+"npc_school06","path");
    add_exit("back", NPCSCHOOL+"npc_school04","path");

} /* setup() */

void reset(){
    if(!womble){
        womble = clone_object(TESTNPC);
        womble->move(TO,"$N wombles in from somewhere.");
    }
} /* reset() */
