/*
** FILE: /domains/School/room/offices.c
**
** Purpose:
**  This is the entrance to the offices for the Faculty at the
**  School.
*/

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_properties( ([ "light" : 2, "indoors" : 1 ]) );
    set_short("The Faculty Offices at The School");
    set_long(
"You are in the lobby of the Faculty Offices at The School. To the "
"north is Miranda's office, and to the south is Soulsinger's. The "
"Faculty Conference Room is up the stairs. To the east lies the "
"Entrance to the School."
    );
      set_exits( ([
        "east"  : "/domains/School/room/entrance",
        "north" : "/domains/School/room/Offices/miranda",
        "south" : "/realms/soulsinger/office",
        "up"    : "/domains/School/room/Offices/confroom",
      ]) );
}
