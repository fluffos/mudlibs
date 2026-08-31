#include <std.h>
#include "ralgoth.h"
inherit ROOM;

void create() {
 ::create();
    set_short("East Ralgoth Street");
    set_property("town", 1);
    set_property("indoors", 1);
    set_listen("default", "An eerie silence pervades the street.");
    set_smell("default", "The rank smell of decaying flesh fills the air.");
    set_long(
	"East Ralgoth Avenue runs through the middle of Ralgoth, alongside "
	"the river that provides the fortress water.  Although it is one of "
        "the main thoroughfares "
	"of Ralgoth, it is sparsely travelled, due to the fear which "
	"grips the city.  It intersects here with the even lesser travelled "
	"Bendek Avenue, which connects the Merchant District to the Magic "
	"district" );
    set_exits( 
              (["west" : RALROOMS"eralg_1",
                "east" : RALROOMS"eralg_3",
		"north" : RALROOMS"nbend_1",
		"south" : RALROOMS"sbend_1"
		]) );


    set_property("light", 1);
    set_property("night light", 1);
    set_items(
        (["road" : "Drolmire Street runs east to the fortress wall.",
          "river" : "A river flows through the center of the fortress, "
	"through the east and west walls."]) );


}

object cleaner;

void reset(){
  ::reset();
	if(!cleaner) {
	cleaner = new(RALMON"cleaner");
	cleaner->move(this_object()); 
	} 
} 
