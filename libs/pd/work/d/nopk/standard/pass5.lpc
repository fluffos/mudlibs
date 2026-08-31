#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
   set_property("mountain",1);
    set("short", "Heading down the Daroq Mountain Pass");
    set("long",
	"The Daroq Mountain Pass cuts through the tall mountain "
        "range like a stone gorge. Caves line the higher section "
        "of the pass, right above you. To the east, the magnificent "
        "adventuring town of Tirun can be seen.");
    set_items(([
        "gorge" : "The gorge is the pass leading through the Daroq Mountains.",
        "pass" : "The pass is lined by caves.",
        "caves" : "They are higher up, above the actual pass.",
        "mountain" : "It towers to the north and south of the pass.",
        ({ "town", "sindarii" }) : "Two roads can be seen from here.",
        "roads" : "Honin cuts east and west through Tirun and "
                  "Veros leads north and south.",
        "veros" : "The lead north-south road cuts through Arulo Juncture",
        "square" : "Adventurers walk through the square constantly.",
        "honin" : "Honin leads east and then west into the great highway.",
        ({ "highway", "great highway" }) : "It leads up into this very pass."
    ]));
    set_exits(([ "east" : ROOMS"pass4",
                 "west" : ROOMS"pass6" ]));
}

void reset() {
 ::reset();
   if (!present("balrog")) {
      new(MOB"balrog2")->move(this_object());
      new(MOB"balrog2")->move(this_object());
   }
}
