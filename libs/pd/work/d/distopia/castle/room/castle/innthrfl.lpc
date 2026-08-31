#include <discastle.h>
inherit VAULT;
void create() 
{
        ::create();
        set_properties((["light" : 2, "indoors" : 1]));
        set("short", "Mad Cow Inn");
        set_long(
        "Shadows cast from the candles lighting the hallway set a somewhat "
        "creepy atmosphere.  The sound from the bottom floor has completly died "
        "away and the dark silence seems to be more appropriate for a place like Distopia. "
        "There is another set of stairs leading up to the fourth floor and another set of rooms "
        "to the east and west"
        );
        set_items
        (([
        "doors"  : "Two thick doors",
        ]));
        set_exits
        (([
                "up"    : ROOMS"innforfl",
                "down" : ROOMS"innsecfl",
                "west"  : ROOMS"innthrfl2",
                "east"  : ROOMS"innthrfl3",
                "room202" : ROOMS"innthrflc2",
                "room203" : ROOMS"innthrflc"
        ]));
set_door("door", ROOMS"innthrflc2", "room203", "keyring");
set_door("door", ROOMS"innthrflc", "room202", "keyring");
}
void reset() {
 ::reset();
set_closed(fixId("door", "room202"), 1);
set_locked(fixId("door", "room202"), 1);
set_closed(fixId("door", "room203"), 1);
set_locked(fixId("door", "room203"), 1);
//ROOMS"innthrflc2"->set_open("door", 0);
//ROOMS"innthrflc2"->set_locked("door", 1);
//ROOMS"innthrflc"->set_open("door 2", 0);
//ROOMS"innthrflc"->set_locked("door 2", 1);
}
