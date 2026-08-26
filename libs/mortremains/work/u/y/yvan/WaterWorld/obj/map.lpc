/* map.c
// A basic map object of the underwater area.
*/

#include <mudlib.h>
#include "/u/d/dragoon/include/format.h"

inherit OBJECT ;

void create() {
    set("id", ({ "map", "rough map" })) ;
    set("short", "a rough map") ;
    set("long", format(
	"An old faded piece of parchment, quite large in size. "
	"Upon closer inspection, it appears to be some sort of map. "
	"Perhaps you could [read] it. "
      )) ;
    set("mass", 5) ;
    set("bulk", 2) ;
}

void init() {
    add_action("read_map", "read") ;
}

int read_map(string str) {
    if(str!= "map") {
	notify_fail("What do you want to read?\n") ;
	return 0 ;
    }
    write(@EndMap
Map of Yvan's Water World:


                     C         Key:
                     |
       M         *-*-*-*        C= entrance to Cave area
       |         | | | |        D= entrance to Deep water area
       *-*       *-*-*-*        M= entrance to mer-folk mansion
       | |       | | | |        O= entrance to Ocean from town
   S-*-*-*-*-*-O-*-*-*-*        P= pub
     |           | | | |        S= shop
     P           *-*-*-*
                   | | |
                   *-*-*
                 /   | |
                D    *-*

EndMap
    ) ;
    return 1 ;
}

/* EOF */
