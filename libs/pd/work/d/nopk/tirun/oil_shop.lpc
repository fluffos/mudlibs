#include <std.h>
#include <tirun.h>

inherit ROOM;

void create()
{
    ::create();
    set_short("The Oil Shop");
    set_properties( ([ "no attack":1,
	"no bump":1,
	"light":2,
	"night light":2,
	"no magic":1 ]) );
    set_long(
      "%^MAGENTA%^Patrick's Herb Shop%^RESET%^\n"
      "The shop is filled with an assortment of flowers and herbs "
      "in all different colors lined up on the wall.  There is a "
      "wooden counter in the southern end of the room.  Behind the "
      "counter on the wall, are many full and empty vials.  A box "
      "on the east wall marked stones glows with an erie green light.  Read "
      "the sign for instructions.");
    set_exits( ([ "out" : ROOMS "square4" ]) );
}

void reset()
{
    ::reset();
    if (!present("patrick")) 
	new(MOB "patrick")->move(this_object());
    if (!present("zelgadiss"))
        new(MOB"zelgadiss")->move(this_object());
}
