#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 1);
    set("short", "The elder guardian's chambers");
    set("long",
        "This is a small room at the heart of the cave. "
        "This must be the tak'daroq's fearsome elder guardian's "
        "chambers. Only a faint smell of the daroq bathroom lingers "
        "here.");
    set_exits(([ "west" : ROOMS"daroq/cave7",
                 "east" : ROOMS"daroq/cave5" ]));
}

void reset() {
 ::reset();
   if (!present("guardian"))
      new(MOB"darguard")->move(this_object());
}
