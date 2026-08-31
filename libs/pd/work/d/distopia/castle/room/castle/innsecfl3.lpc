#include <discastle.h>
inherit VAULT;
void create() 
{
        ::create();
        set_properties((["light" : 2, "indoors" : 1]));
        set("short", "Mad Cow Inn");
        set_long("Further down the hallway to the east of the staircase
that leads back down to the inn is another set of rooms.");
        set_items
        (([
        "doors"  : "Two thick doors",
        ]));
        set_exits
        (([
                "west"  : ROOMS"innsecfl",
                "room101" : ROOMS"innsecflroome",
                "room100" : ROOMS"innsecflroome2"
        ]));
set_door("door", ROOMS"innsecflroome", "room101", "keyring");
set_door("door", ROOMS"innsecflroome2", "room100", "keyring");
}
void reset() {
 ::reset();
set_closed(fixId("door", "room100"), 1);
set_locked(fixId("door", "room100"), 1);
set_closed(fixId("door", "room101"), 1);
set_locked(fixId("door", "room101"), 1);
//ROOMS"innsecflroome"->set_open("door", 0);
//ROOMS"innsecflroome"->set_locked("door", 1);
//ROOMS"innsecflroome2"->set_open("door 2", 0);
//ROOMS"innsecflroome2"->set_locked("door 2", 1);
}
