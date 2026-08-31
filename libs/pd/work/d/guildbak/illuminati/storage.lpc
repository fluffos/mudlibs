#include <std.h>
#include <guild.h>
inherit ROOM;
int i = 0;
void
create()
{
    ::create();
    set_short("storage room");
    set_long("This is the storage room. Get the hell out of here.");
    set_exits(([ "south" : ROOMS"illuminati/itemshop", ]));
}
void
reset()
{
    ::reset();
    while(++i < 5) {
            if(!present("hole"))
            new(ROOMS"illuminati/obj/black_hole")->move(this_object());
        if(!present("gauntlet"+i))
            new(ROOMS"illuminati/obj/a_gauntlet")->move(this_object());
        if(!present("divine"+i))
            new(ROOMS"illuminati/obj/divinesword")->move(this_object());
    }
}
