// May's Ed Tutorial for Wizards
// brought to FF on 5 Feb 2001
// brought to Riftwar and modified to work here 7/02/01 - Shaydz
#include "defs.h";
inherit ROOM_OBJ;

void setup(){
  set_light(80);
  set_short("Ed Tutorial 1");
  set_long(
    "   Welcome to the world of ED.  "
    "In this land you will learn about the "
    "editor that the Wizards use here at " + MUD_NAME +
    "It is called ED.\n   On your journey through these "
    "tutorial rooms, pay careful attention to the things "
    "that Ed has to say.  He is an expert when it comes to "
    "this editor.  He should be, it was named after him.\n"
    "   Now once you are in ED, you have a new bunch of commands that "
    "you must learn.  Remember, all the other commands that you "
    "normally use as a wizard like <goto> and <tell> will not work "
    "WITHIN ED.  So, what you must do if you want to use a 'regular' "
    "character command is put a <!> before the statement.  This "
    "tells ED that the command is not an ED command but is a regular "
    "command and allows you to execute that command.  This will "
    "be very helpful when you have questions to ask others when "
    "you are editing.\n   So to begin on your journey into the land "
    "of ED, just type <north>.  The same command holds true throughout "
    "these rooms.  To go south to the previous room, type <south>.  "
    "That is all you need to know to get you started using the program ED.\n");

  add_exit("north", EDTUTOR "edtutor02", "path");
add_exit("back", GETSTART "start","path");
}
