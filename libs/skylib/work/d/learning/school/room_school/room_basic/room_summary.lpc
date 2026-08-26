// Basic room school by Avelan
// room_summary
// May 2001
#include "defs.h";
inherit ROOM_OBJ;

void setup(){
    set_light(100);
    set_short("room school summary");
    set_determinate("the ");
    /*
    * You must be wondering what the heck is the next
    * function.  It looks like set_long but is a little
    * different from what you have just learned.
    * This is the OLD style which forces the players
    * client to wrap the text the way you want it.
    * This should NOT be used but in very special cases,
    * a simple rule, don't use it anywhere where the players
    * have access.
    */

    set_long(@AVE

Ok, here we are.  You should have learned now how to
create a simple room which reacts to the time of the day,
has room_chats and interesting add_items.  Also you should
know the basics of inheritance and the use of definitions.
If you feel you don't, you should go back and check those
things.  Also if something here wasn't explained properly,
please post a note on the learning board and we will
try to fix it.
Note that the room school continues in the advanced school,
this is just to get you started.

Let's move on to the npc school.

AVE
    );

    add_exit("finish", ROOMSCH "start","path");
    add_exit("backward",ROOMSC "room_school04","path");

}
