#include <std.h>
#include <shadow.h>

inherit ROOM;

void create()
{
 ::create();
 set_short("A Magic Shop");
 set_properties( ([ "no attack":1,
                    "no bump":1,
                    "light":2,
                    "night light":2,
                    "no magic":1 ]) );
 set_long("The shop seems to glow all over, lighting everything up "
          "evenly.  There are all sorts of assorted magical items laying "
          "around the room. Behind a counter stands a tall magician "
          "who seems quite preoccupied with his studies.");

 set_exits( ([ "west" : ROOMS "tene14" ]) );
}

void reset()
{
 ::reset();
 if (!present("goldar")) 
   new(MOB "goldar")->move(this_object());
}
