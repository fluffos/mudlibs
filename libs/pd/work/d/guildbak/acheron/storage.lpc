#include <std.h>
#include <guild.h>
inherit ROOM;
int i = 0;

void
create()
{
    ::create();
   set_properties((["light":2, "night light":3, "no teleport":1]));
    set_short("storage room");
    set_long("This is the Acheron's storage room. Get the hell out of here.");
    set_exits(([ "south" : ROOMS"acheron/shop", ]));
}

void
reset()
{
    ::reset();
    while(++i < 3) {
        if(!present("sash "+i))
            new(ROOMS"acheron/sash")->move(this_object());
               if(!present("websack "+i))
            new(ROOMS"acheron/websack")->move(this_object());

       }
}
