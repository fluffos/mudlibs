/*
* add_command example room for the cre school
* 27 Feb '02 by Avelan
*
* A room that has a note in it that you can tear.
*/

#include "defs.h"
inherit ROOM_OBJ;

object note;

void setup(){
    set_light(100);
    set_short("example room");
    set_long("This room has a note in it that has an add_command"
      " that makes it possible to tear up the note.  Pick up the note"
      " and do 'more note' to see how it is coded.  The code has comments"
      " in it that are inside * marks, they aren't a part of the code"
      " obviously.\n");

    add_exit("back",ADD_SC "start","path");

} /* setup() */

void reset(){
    if(!note){
        note = clone_object("/d/learning/school/items/note");
        note->move(TO);
    }
} /* reset() */
