#include <std.h>
#include "../pass.h"
inherit ROOM;

void create(){
    ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
    set_property("light" , 2);
    set_property("indoors" , 0);
    set_short("On Dragon Pass Road");
    set_long(
@MELNMARN
%^BOLD%^You are walking on the Dragon Pass Road.%^RESET%^
%^CYAN%^All around you lie the Charu Mountains. They are very intimidating, looming high in the sky. The road winds through the mountains. A %^ORANGE%^small wooden cabin %^CYAN%^has been built along the mountainside.
MELNMARN
);

    set_smell("default","You can smell the fresh mountain air.");
    set_listen("default","You can hear the wind blowing through the valleys.");
    set_items(([
        "road":"A new road through the mountains.",
        ({"mountains","mountain","glint","top","peak","snow"}):"The mountains rise up above you, high into the air.  From this vantage point you can just make out the highest peak and the blackened scar that shreads its one side.  It is hard to tell, but it would seem something is lodged up there still.  Though what is hard to say.  An explosion has spewed a lot of its structure into every which direction.",
        "cabin":"%^RESET%^%^CRST%^%^C058%^This is pretty typical for a small cabin, with a couple windows and a simple wooden entryway. However, parts of it look newer than others. It seems like someone has regularly had to make repairs to it, in %^C124%^catastrophic %^C058%^proportions.%^CRST%^",
        ]));
    set_exits(([
        "southeast" : PASSDIR+"pass22",
        "northeast" : PASSDIR+"pass24",
        "west" : "/d/common/obj/daily/entrance",
        ]));
}

