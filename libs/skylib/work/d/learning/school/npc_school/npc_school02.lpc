/**
 * Basic npc making
 * October '01 by Avelan
 */

#include "defs.h"

#define TESTNPC "/d/learning/school/characters/butterfly"

inherit ROOM_OBJ;

object butterfly;

void setup(){
    set_zone("npc_school");
    set_short("npc room");
    set_light(100);
    set_long("This room explains how to clone an npc"
      " into a room using a file at every reset if there"
      " isn't one present already.  'More here' to see how"
      " it works.  Here you can also 'more' the npc"
      " itself and see how it is coded.  It is"
      " basically the same as the one in the previous"
      " room but it also moves around the npc school"
      " and it has it's own file.\n");

    /* No add_items here to make the code a bit easier to
    * read.
    */

    add_exit("forward", NPCSCHOOL+"npc_school03","path");
    add_exit("back", NPCSCHOOL+"npc_school01","path");

} /* setup() */

/* reset() is called at every reset of the room.
* The if() statement checks if there is no butterfly
* present at reset and if so, it clones one and
* moves it to this object.
* So, TO is defined to be this_object() and
* TESTNPC, as you can see at the top, is defined to
* be /d/learning/school/characters/butterfly.c
* The string in move() is the message to
* use when moving the butterfly in here.
*/

void reset(){
    if(!butterfly){
        butterfly = clone_object(TESTNPC);
        butterfly->move(TO,"$N flies in from somewhere.");
    }
} /* reset() */

