#include <discastle.h>
inherit VAULT;
void create() 
{
        ::create();
        set_properties((["light" : 2, "indoors" : 1]));
        set("short", "Mad Cow Inn");
        set_long("Further down the hallway to the west of the staircase
that leads back down to the inn is another set of rooms exactly like all the rest.");
        set_items
        (([
        "doors"  : "Two thick doors",
        ]));
        set_exits
        (([
                "east"  : ROOMS"innthrfl",
                "room204" : ROOMS"innthrflroomw2",
                "room205" : ROOMS"innthrflroomw"
        ]));
set_door("door", ROOMS"innthrflroomw2", "room204", "keyring");
set_door("door", ROOMS"innthrflroomw", "room205", "keyring");
}
void reset() {
 ::reset();
set_closed(fixId("door", "room204"), 1);
set_locked(fixId("door", "room204"), 1);
set_closed(fixId("door", "room205"), 1);
set_locked(fixId("door", "room205"), 1);
//ROOMS"innthrflroomw2"->set_open("door", 0);
//ROOMS"innthrflroomw2"->set_locked("door", 1);
//ROOMS"innthrflroomw"->set_open("door 2", 0);
//ROOMS"innthrflroomw"->set_locked("door 2", 1);
}
