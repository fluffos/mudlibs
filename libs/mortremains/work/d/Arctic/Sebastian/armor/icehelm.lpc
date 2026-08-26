/*
**File: icehelm.c
**Date: June 18th, 1 triple-9
**Purpose: It's a helm, made of ice, nuff said.
**Other Comments: Yeah, I got your comments right here!
**
*/

#include <mudlib.h>
#include <magic.h>

inherit ARMOR;

void create() {
    //short is what you see w/o an examine
    set("short","an ice helm");

    //long is what is seen when the object is examined. the @SuckMe
    //statement allows you to write a long description without useing
    // n\"+ all the time
    set("long", @Suckme
It's a helm, made entirely of ice.  Hollowed from the strongest glaciers
It is fur lined for comfort.
Suckme
    );

    //this allows a player to exa the item in more ways than 1
	set("id",({"helm","ice helm","icehelm","helmet"}) );

    //armor_type makes it a type of armor, thew other types can be found
    //in /doc/properties
	set_armor_type("helmet");
}
