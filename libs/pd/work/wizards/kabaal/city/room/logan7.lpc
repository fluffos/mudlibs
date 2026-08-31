#include <std.h>
#include <kabaal.h>
inherit ROOM;

void create(){
 ::create();
set_short("Logan");
   set_long("The road here goes north and south. The enterance to a medium sized building "
           "is here. The building is two stories. The door, which is cracked open a bit, is "
           "made of mahagony. Several windows stare down at the street. Two stone steps lead "
	   "up to the building. ");
set_items( 
          ([ "street" : "The street appears to be old and cracked. It leads north and west "
			"of here.",
	     "ground": "The ground is starting to solidify that it is out of the forest.",
	     "city": "You stand in the city.",
	     "building": "The building is two stories tall. Several windows look down upon the "
			 "city. A door rests open a hair, leaving an open invitation." ]) );
set_property("light", 3);
set_property("night light", 2);
set_listen("default", "Faint murmuring and noises from the forest intertwine with eachother.");
set_exits( (["north" : ROOMS "square",
	     "enter" : ROOMS "en3",
             "south" : ROOMS "logan6"]) );
}
