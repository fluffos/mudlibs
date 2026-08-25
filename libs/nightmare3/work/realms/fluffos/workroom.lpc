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
    set_short("a new workroom");
    set_long(
      "This is the grand workroom of a new immortal.  "
      "Inventive new realms will originate here."
    );
    set_exits( ([ "square" : "/domains/standard/square" ]) );
    set_items( ([ "workroom" : "Code is being created here." ]) );
    set_smell("default", "It smells like a new immortal.");
    set_listen("default", "The sounds of code creation vibrate the room.");
}
