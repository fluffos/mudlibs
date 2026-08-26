/*
** FILE: /domains/School/room/offices/confroom.c
**
** Purpose:
**  This is the meeting place for the Faculty of the School so that
**  they can meet and discuss without spamming everyone at the center.
**  =)
*/

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_properties( ([ "light" : 2, "indoors" : 1 ]) );
    set_short("The Faculty Conference Room");
    set_long(
"You are in the Faculty Conference room. A large oval table fills "
"most of this room, with the chairs taking whatever is left over. "
"Recessed into the desk, in front of each chair, is a computer "
"terminal.\n\nThe only visible exit is down the staircase which "
"leads to the Faculty offices below."
    );
  set_exits( ([
    "down"  : "/domains/School/room/offices",
  ]) );
}
