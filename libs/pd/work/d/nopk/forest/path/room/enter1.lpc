#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("In a cottage");
    set_long(
      "This cottage is rather quaint. A small wooden table with a few "
      "chairs sitting around it rests in the corner. An old throw rug "
      "partially covers the floor. Two burning candles sit on the table. "
      "A chest burried in dust lies against the west wall."
    );
    set_items(([
   "chest" : "The chest rests up against the western wall. It is covered "
             "in nearly an inch of dust.",
   "table" : "It's just a wooden dining table. Several chairs sit around "
             "it and two burning candles have been placed there.",
   "chairs" : "A couple of wooden chairs sit around the table. They don't "
              "look too overly comfortable.",
   "candles" : "Two candles have been lit and are now sitting on the table.
Wax "
               "pours down the side of the candles.",
   "rug" : "An old Oriental throw rug lies on the floor, covering most of it."
    ]));
    set_exits( ([ 
        "out" :  "/d/nopk/forest/path/room/forest8",
        "north" :  "/d/nopk/forest/path/room/enter2",
        "down"  : "/d/nopk/forest/path/room/enter3"
    ]) );
}
