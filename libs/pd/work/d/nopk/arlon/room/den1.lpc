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
    set_exits( ([ "west" : ROOMS "den" ]) );
}

void reset()
{
    ::reset();
    if (!present("simba"))
    {
	new( MOB "simba")->move(this_object());
    }
    if (!present("mufasa"))
    {
	new( MOB "mufasa")->move(this_object());
    }
}

