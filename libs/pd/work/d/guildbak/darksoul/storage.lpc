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
    set_long("This is the darksoul's storage room. Get the hell out of here.");
    set_exits(([ "south" : ROOMS"darksoul/shop", ]));
}

void
reset()
{
    ::reset();
    while(++i < 5) {
        if(!present("blade "+i))
            new(DARKSOUL"wep/bladeofsouls")->move(this_object());
        if(!present("staff "+i))
            new(ROOMS"darksoul/vstaff")->move(this_object());
        if(!present("leggings "+i))
            new(ROOMS"darksoul/dsleggings")->move(this_object());
        if(!present("fly-blanket "+i))
            new(ROOMS"darksoul/flyblanket")->move(this_object());
        if(!present("dknife "+i))
            new(ROOMS"darksoul/dknife")->move(this_object());
        if(!present("dknife "+i))
            new(ROOMS"darksoul/dknife")->move(this_object());
        if(!present("sack "+i))
            new(ROOMS"darksoul/sack")->move(this_object());
    }
}
