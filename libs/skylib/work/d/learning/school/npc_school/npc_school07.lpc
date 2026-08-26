/*
* Summary for the npc_school
* Jan '02 by Avelan
*/

#include "defs.h"
inherit ROOM_OBJ;

void setup(){
    set_light(70);
    set_zone("npc_school");
    set_short("npc school summary");
    set_long("So, now you should have some idea"
      " on how to do a simple npc that only stands"
      " in room, an npc which wanders around, an"
      " interactive npc which responds to tells and"
      " also how to clone npcs to a room via a search"
      " function.\nThere is still a lot to learn, no "
      "doubt about it but you're not alone so remember"
      " to ask for help whenever you need it.\n");

    add_exit("finish",NPCSCHOOL+"start","path");
    add_exit("back",NPCSCHOOL+"npc_school06","path");

} /* setup() */
