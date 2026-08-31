#include <std.h>
#include <arlon.h>

inherit ROOM;

void create()
{
    ::create();
    set_short("Lions den");
    set_long("This is a lion's den.  A small tunnel fades into the "
      "darkness.  The corpses of many different animals litter the floor.");
    set_listen("default", "The roaring of lions can be heard.");
    set_exits( ([ "west" : ROOMS "plains21",
	"east" : ROOMS "den1" ]) );
}

void reset()
{
    ::reset();
    if (!present("cub"))
    {
	new( MOB "cub")->move(this_object());
	new( MOB "cub")->move(this_object());
    }
    if (!present("furry lion"))
    {
	new( MOB "lion")->move(this_object());
	new( MOB "lion")->move(this_object());
    }
}

