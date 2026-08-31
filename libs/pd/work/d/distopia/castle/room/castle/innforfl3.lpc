#include <discastle.h>
inherit VAULT;
void create() 
{
        ::create();
        set_properties((["light" : 2, "indoors" : 1]));
        set("short", "Mad Cow Inn");
        set_long("Yup, another twin set of doors leading to two more rooms
for patrons to sleep off nights of drinking");
        set_items
        (([
        "doors"  : "Two thick doors",
        ]));
        set_exits
        (([
                "west"  : ROOMS"innforfl",
                "room301" : ROOMS"innforflroome2",
                "room300" : ROOMS"innforflroome"
        ]));
set_door("door", ROOMS"innforflroome2", "room301", "keyring");
set_door("door", ROOMS"innforflroome", "room300", "keyring");
}
void reset() {
 ::reset();
set_closed(fixId("door", "room300"), 1);
set_locked(fixId("door", "room300"), 1);
set_closed(fixId("door", "room301"), 1);
set_locked(fixId("door", "room301"), 1);
//ROOMS"innforflroome"->set_open("door", 0);
//ROOMS"innforflroome"->set_locked("door", 1);
//ROOMS"innforflroome2"->set_open("door 2", 0);
//ROOMS"innforflroome2"->set_locked("door 2", 1);
}
