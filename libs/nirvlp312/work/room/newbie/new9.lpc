#include "/include/mudlib.h"
inherit ROOM;

void reset(status arg) {
  if (!arg) {
    set_short("the elfin forest");
    set_long(
"The forest seems to get darker in these parts.  There is a strong sense  \n"+
"of evil in the air.  The trees aren't even the same.  They seem to be of \n"+
"poorer quality, and all of their leaves have either fallen off, or turned\n"+
"brown.\n");
    set_exits(({
      "room/newbie/new8", "east",
      "room/newbie/new12", "north",
      "room/newbie/new10", "west",
    }));
    set_weather(2, 4, 3);
  }
}

