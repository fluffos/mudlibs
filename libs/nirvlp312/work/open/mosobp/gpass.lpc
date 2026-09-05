#include "ansi.h"
inherit "room/room";

    void reset(status arg) {
    if (arg) return;
    set_light(1);
    short_desc = HIC+"Gumdrop Pass"+NORM;
    items = ({
        "icicles","Glistening daggers of ice cling to the mountain",
        "sparkling icicles","Glistening daggers of sparkling ice",
        "pass","The pass provides a shortcut to many",
        "mountains","The looming Gumdrop Mountains",
        "dreary gloom","Dark and dreary, gloom sets in",
        "gloom","Dark and dreary, gloom sets in"});
        
    long_desc =
"   Gumdrop Pass leads further into Candy Land, allowing one to pass\n\
quickly through the Gumdrop Mountains.  The pass has sparkling icicles\n\
on one side and dreary gloom on the other.\n";
    dest_dir = ({"players/martha/area/rooms/road", "north",
                 "players/martha/area/rooms/gmtn", "south"});
}