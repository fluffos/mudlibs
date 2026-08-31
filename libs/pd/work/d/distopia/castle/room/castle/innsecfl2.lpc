#include <discastle.h>
inherit VAULT;
void create() 
{
        ::create();
        set_properties((["light" : 2, "indoors" : 1]));
        set("short", "Mad Cow Inn");
        set_long("Further down the hallway to the west of the staircase
that leads back down to the inn is another set of rooms.");
        set_items
        (([
        "doors"  : "Two thick doors",
        ]));
        set_exits
        (([
                "east"  : ROOMS"innsecfl",
                "room104" : ROOMS"innsecflroomw2",
                "room105" : ROOMS"innsecflroomw"
        ]));
set_door("door", ROOMS"innsecflroomw2", "room104", "keyring");
set_door("door", ROOMS"innsecflroomw", "room105", "keyring");
}
void reset() {
 ::reset();
set_closed(fixId("door", "room104"), 1);
set_locked(fixId("door", "room104"), 1);
set_closed(fixId("door", "room105"), 1);
set_locked(fixId("door", "room105"), 1);
//ROOMS"innsecflroomw2"->set_open("door 2", 0);
//ROOMS"innsecflroomw2"->set_locked("door 2", 1);
//ROOMS"innsecflroomw"->set_open("door", 0);
//ROOMS"innsecflroomw"->set_locked("door", 1);
}
