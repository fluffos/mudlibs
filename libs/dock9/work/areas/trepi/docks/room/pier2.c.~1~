/* /areas/trepi/docks/room/pier2.c

 emsenn@Dock 9
 091005
 First room new players see, a dock in Trepi.

*/

inherit ROOM;

void create(){
    set_light(1);
    set_short("Pier");
    set_domains("trepi",({"docks"}));
    set_long("This is southern pier in Trepi.  To the north is Dock 8, to "
      "the south is Dock 11, and the pier continues and and west of here.");
    set_items( ([
      ]) );
    set_exits(([
        "north" : __DIR__ +"dock8.c",
	    "south" : __DIR__ +"dock11.c",
        "east" : __DIR__ +"pier1.c",
        "west" : __DIR__ +"pier3.c",
      ]) );
}
