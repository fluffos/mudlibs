#include <std.h>
#include <arlon.h>

inherit ROOM;

void create()
{
 ::create();
 set_short("Store");
 set_long("You are in Johns Boat Shop. He seems to be very busy in the "
          "back assembling boats. There is an assortment of large "
          "and small lumber stacked up against the wall. Torches on "
          "the wall light up the store.");
 set_exits( ([ "south" : ROOMS "pier" ]) );
 set_properties( ([ "light" : 2, "night light":2, "no attack":1,
                    "no bump":1 ]) );
}

void reset()
{
 if (!present("john"))
   new(MOB "john")->move(this_object());
}
