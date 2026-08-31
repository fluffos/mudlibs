#include <std.h>
#include <shadow.h>

inherit ROOM;

void create()
{
 ::create();
 set_short("Oil Shop");
 set_properties( ([ "no attack":1,
                    "no bump":1,
                    "light":2,
                    "night light":2,
                    "no magic":1 ]) );
 set_long("The shop is filled with an assortment of flowers and herbs "
          "in all different colors lined up on the wall. There is a "
          "wooden counter in the southern end of the room. Behind the "
          "counter on the wall are many full and empty vials.");

 set_exits( ([ "east" : ROOMS "tene14" ]) );
}

void reset()
{
 ::reset();
 if (!present("vincent")) 
   new(MOB "vincent")->move(this_object());
}
