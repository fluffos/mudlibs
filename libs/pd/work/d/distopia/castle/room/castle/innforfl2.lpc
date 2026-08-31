#include <discastle.h>
inherit VAULT;
int moo = 1;
void create() 
{

        ::create();
        set_properties((["light" : 2, "no scry" : 1,"indoors" : 1]));
        set("short", "Mad Cow Inn");
        set_long("Further down the hallway to the west of the staircase
that leads back down to the inn is another set of rooms exactly like all the rest.");
        set_items
        (([
        "doors"  : "Two thick doors",
        ]));
        set_exits
        (([
                "east"  : ROOMS"innforfl",
                "room304" : ROOMS"innforflroomw",
                "room305" : ROOMS"innforflroomw2"
        ]));
set_door("door", ROOMS"innforflroomw", "room304", "keyring");
set_door("door", ROOMS"innforflroomw", "room305", "keyring");
}
void reset() {
 ::reset();
set_closed(fixId("door", "room304"), 1);
set_locked(fixId("door", "room304"), 1);
set_closed(fixId("door", "room305"), 1);
set_locked(fixId("door", "room305"), 1);
//ROOMS"innforflroomw"->set_open("door", 0);
//ROOMS"innforflroomw"->set_locked("door", 1);
//ROOMS"innforflroomw2"->set_open("door 2", 0);
//ROOMS"innforflroomw2"->set_locked("door 2", 1);
moo = 1;
}
