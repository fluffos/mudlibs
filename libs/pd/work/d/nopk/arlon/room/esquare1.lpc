#include <std.h>
#include <arlon.h>


inherit ROOM;

void create()
{
    ::create();
    set_short("east of arlon.");
    set_long("The cobblestone path continues to the east.  Shrubs and plants outline "
      "the path east of Arlon square.  Trees hang over the path providing shade to the "
      "people who walk the streets.  The path has many dusty footprints on it.");

    set_exits( ([
	"east": ROOMS "esquare2",
	"west" : ROOMS "square" ]) ); 
}

void reset()
{
    ::reset();
    if (!present("townsman"))
	new (MOB "townsman")->move(this_object());
}
