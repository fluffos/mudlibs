/*
** FILE: /domains/School/room/Classes/hall1.c
**
** Purpose:
**  A part of the long hallway that leads to the classrooms.
*/

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_properties( ([ "light" : 2, "indoors" : 1 ]) );
    set_short("A Long Hallway");
    set_long(
"You are in a long hallway. There are exits to the west and east. To "
"the north and south are classrooms."
    );
  set_exits( ([
    "west"  : "/domains/School/room/entrance",
    "east"  : "/domains/School/room/Classes/hall2",
    "north" : "/domains/School/room/Classes/room1n",
    "south" : "/domains/School/room/Classes/room1s",
  ]) );
}
