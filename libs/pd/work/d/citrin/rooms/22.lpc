//  Created by Whit
#include <std.h>
#include <citrin.h>
inherit ROOM;
void create() {
    ::create();
    set_name("near a lake");
    set_short("near a lake");
    set_long("A huge bee's nest stands on the catwalk preventing anyone "
      "from traveling any further down the catwalk.  Several of the "
      "bees swarm in and out of the hive bringing food to their "
      "queen.  Honey seems to seep out of the entrance of the "
      "hole.  Perhaps, someone could fit in the hive.");
    set_items(([
      ]));
    set_exits(([
	"northeast":ROOMS"21",
      ]));
    set_properties((["light":1,"night light":1,"forest":1,]));
}

void reset() {
    ::reset();
    if(!present("hive"))
	new(OBJ"hive")->move(this_object());
}
