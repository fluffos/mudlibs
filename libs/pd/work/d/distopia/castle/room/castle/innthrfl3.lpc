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
                "west"  : ROOMS"innthrfl",
                "room201" : ROOMS"innthrflroome",
                "room200" : ROOMS"innthrflroome2"
        ]));
set_door("door", ROOMS"innthrflroome", "room201", "keyring");
set_door("door", ROOMS"innthrflroome2", "room200", "keyring");
}
void reset() {
 ::reset();
set_closed(fixId("door", "room200"), 1);
set_locked(fixId("door", "room200"), 1);
set_closed(fixId("door", "room201"), 1);
set_locked(fixId("door", "room201"), 1);
//ROOMS"innthrflroome2"->set_open("door", 0);
//ROOMS"innthrflroome2"->set_locked("door", 1);
//ROOMS"innthrflroome"->set_open("door 2", 0);
//ROOMS"innthrflroome"->set_locked("door 2", 1);
}
