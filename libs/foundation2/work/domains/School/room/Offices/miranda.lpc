/*    /std/obj/workroom.c
    from Nightmare IV
    a standard workroom style object for new immortals
    created by Descartes of Borg 940316
*/

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_properties( ([ "light" : 2, "indoors" : 1 ]) );
    set_short("Miranda's Office");
    set_long(
"You are in Miranda's Office. A small desk, chair, and a windows "
"are all the furnishings contained in this sparse room."
    );
  set_exits( ([
    "south" : "/domains/School/room/offices",
    "north" : "/realms/miranda/workroom",
  ]) );
    set_items( ([
     "portrait" : "This is a picture of Miranda with her husband, Delegath, an Aracoix ranger on ChaosMUD.",
      "desk" : "This is a small oak desk. On it you see a picture of Miranda and her husband.",
      "chair" : "This leather swivel chair looks incredibly comfortable."
]) );
}
