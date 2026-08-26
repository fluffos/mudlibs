// Start room for room_school
// October '01 by Avelan

#include "defs.h"
inherit ROOM_OBJ;

void setup(){

    set_short("start room");
    set_light(100);
    set_long("Ok, before we start, some very important things"
      " about descriptions in general.  Keep these in mind"
      " when doing any descriptions.\n\nTell the player what"
      " is in _this_ particular room, not what can be found"
      " in the next one.\nTell me about textures, colours,"
      " materials and the sort.\n\nNEVER ever use 'you'"
      " or 'your' in any descriptions.  Never tell the"
      " player how they feel or from where they came to"
      " this room, since you can't know those things.\n"
      "Ok, now let's continue with the actual coding stuff"
      " in the next room.\n");


    add_exit("basic rooms",ROOMSC "room_school01","path");
    add_exit("terraintutor", TERRAINTUTOR "foyer","path");
    add_exit("situations", SIT+"sitroom1","path");
    add_exit("back",SCHOOL "school","path");

} /* setup() */
