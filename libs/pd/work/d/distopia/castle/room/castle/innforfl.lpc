#include <discastle.h>
inherit VAULT;
void create() 
{
        ::create();
        set_properties((["light" : 2, "indoors" : 1]));
        set("short", "Mad Cow Inn");
        set_long(
  		"The highest floor of the inn is even more dark, gloomy, and spooky. "
  		"Here the only sounds is the steady rythmic breathing and a small squeek "
  		"on the floor boards"
        );
        set_items
        (([
        "doors"  : "Two thick doors",
        "floor boards" : "They look like they need to be repaired."
        ]));
        set_exits
        (([
                "down" : ROOMS"innthrfl",
                "west"  : ROOMS"innforfl2",
                "east"  : ROOMS"innforfl3",
                "room302" : ROOMS"innforflc2",
                "room303" : ROOMS"innforflc"
        ]));
set_door("door", ROOMS"innforflc", "room303", "keyring");
set_door("door", ROOMS"innforflc2", "room302", "keyring");
}
void reset() {
 ::reset();
set_closed(fixId("door", "room302"), 1);
set_locked(fixId("door", "room302"), 1);
set_closed(fixId("door", "room303"), 1);
set_locked(fixId("door", "room303"), 1);
//ROOMS"innforflc2"->set_open("door", 0);
//ROOMS"innforflc2"->set_locked("door", 1);
//ROOMS"innforflc"->set_open("door 2", 0);
//ROOMS"innforflc"->set_locked("door 2", 1);
}
