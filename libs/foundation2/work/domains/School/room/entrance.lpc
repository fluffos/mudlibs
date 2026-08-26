/*
** FILE: /domains/School/room/entrance.c
**
** Purpose:
**  This is the entrance the the School at Idea Exchange.
*/

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_properties( ([ "light" : 2, "indoors" : 1 ]) );
    set_short("The School Entrance");
    set_long(
"You are in the Entrance Arch of the School. Vines twist and grip the "
"stonework as it works its way upwards in its unending struggle to "
"cover the archway with its leaves.\n\nTo the west lies the Faculty "
"offices and the classrooms are east of here."
    );
      set_exits( ([
        "south" : "/domains/Standard/center",
        "west"  : "/domains/School/room/offices",
      "east"  : "/domains/School/room/Classes/hall1",
      ]) );
}
