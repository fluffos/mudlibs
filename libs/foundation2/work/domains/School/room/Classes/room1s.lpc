/*
** FILE: /domains/School/room/Classes/room1s.c
**
** Purpose:
**  A Classroom.
*/

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_properties( ([ "light" : 2, "indoors" : 1 ]) );
    set_short("A Classroom");
    set_long(
"You are in the room <"+file_name(this_object())+".c>. This classroom, "
"like all the others, is very sparse containing just desks for the "
"teacher and students. Outside, through the one windows in this room, "
"you see wildflowers blooming in the constant spring-summer "
"environment sustained by the magic and technology of the School."
    );
  set_exits( ([
    "north" : "/domains/School/room/Classes/hall1",
  ]) );
}
