#include <std.h>
#include <kabaal.h>
inherit ROOM;

void create()
{
 ::create();
set_short("Logan");
   set_long("A narrow street leads north and south. A small building "
           "lies east of here. The building is one story with weathered "
           "stone steps leading up to it. The door is a dark mahagony, "
           "and rests part way open. Off to the northeast, a mountain "
	   "range is visable to the naked eye.");
set_items( 
          ([ "buildings" : "Several old-looking buildings are seen ahead.",
             "mountain": "It doesn't look very tall.",
             "city": "You are standing in the city.",
             "gates": "The large gates are south of here.",
             "building" : "Wonder what's inside..." ]) );
set_property("light", 3);
set_property("night light", 2);
set_listen("default", "Everyday talk fills the air.");
set_exits( (["north" : ROOMS "logan9",
	     "enter" : ROOMS "en1",
              "south" : ROOMS "logan3"]) );
}
