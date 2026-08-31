#include <discastle.h>
inherit VAULT;
void create() 
{
        ::create();
        set_properties((["light" : 2, "indoors" : 1]));
        set("short", "Mad Cow Inn");
        set_long("The noise down stairs is much duller now as one gets
into the inn proper. Hallways stretch in either directions leading to small
rooms.  Another flight of stairs leads up.");
        set_items
        (([
        "doors"  : "Two thick doors",
        ]));
        set_exits
        (([
                "up"    : ROOMS"innthrfl",
                "down" : ROOMS"innbar",
                "west"  : ROOMS"innsecfl2",
                "east"  : ROOMS"innsecfl3",
                "room102" : ROOMS"innsecflc",
                "room103" : ROOMS"innsecflc2"
        ]));
set_door("door", ROOMS"innsecflc", "room102", "keyring");
set_door("door", ROOMS"innsecflc2", "room103", "keyring");
}
void reset() {
 ::reset();
set_closed(fixId("door", "room102"), 1);
set_locked(fixId("door", "room102"), 1);
set_closed(fixId("door", "room103"), 1);
set_locked(fixId("door", "room103"), 1);
 /*
ROOMS"innsecflc"->set_open("door", 0);
ROOMS"innsecflc"->set_locked("door", 1);
ROOMS"innsecflc2"->set_open("door 2", 0);
ROOMS"innsecflc2"->set_locked("door 2", 1);
 */
}
