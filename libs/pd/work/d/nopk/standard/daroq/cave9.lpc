#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 1);
    set("short", "In a tunnel within the daroq caves");
    set("long",
        "Sharp jagged rocks are a vision of things to come. The "
        "Daroqs are known to throw their dead victims over large "
        "cliffs. The passage down looks a fairly safe falling distance "
        "from here.");
    set_exits(([ "up" : ROOMS"daroq/cave10",
                 "down" : ROOMS"daroq/cave8" ]));
}

void reset() {
 ::reset();
   if (!present("daroq")) {
      new(MOB"takdar")->move(this_object());
      new(MOB"takdar")->move(this_object());
      new(MOB"takdar")->move(this_object());
   }
   if (!present("tak'daroq")) {
      new(MOB"takdaroq")->move(this_object());
      new(MOB"takdaroq")->move(this_object());
   }
}
