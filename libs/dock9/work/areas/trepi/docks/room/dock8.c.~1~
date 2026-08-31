/* /areas/trepi/docks/room/dock8.c

 (emsenn and abzde)@Dock 9
 091212
 One of the docks in Trepi.

*/

inherit ROOM;

void create(){
    set_light(1);
    set_short("Dock 8");
    set_domains("trepi",({"docks"}));
    set_long("This is the Dock 8, one of the six docks in the town of Trepi.  "
      "There are docks to the east and west; the one to the west seems to be a "
      "bit different, in some undefineable way.");
    set_items(([
        ({"dock","dock 8"}):"This is one of the docks off of the pier in Trepi.  It appears to be in decent condition, though the wood does look to be a bit odd.",
        ({"trepi","town"}):"The town is to the northeast of here.",
        ({"pier"}):"The dock is attached to the pier just south of here.",
        ({"wood"}):"Upon closer inspection, it is apparent that this dock is not actually made from wood, but is, instead, constructed of cheese.",
        ({"west","dock 9"}):"UNDEFINED",
        ({"east","dock 7"}):"DENIFEDNU",
        ({"cheese"}):"Mmmmm cheese.",
      ]));
    set_exits(([
        "south" : __DIR__ +"pier2.c",
      ]) );
}

