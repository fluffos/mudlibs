#include <config.h>
#include <mudlib.h>
#include "/d/Prime/Asylum/asy.h",

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
set( "short", "Asylum Grounds" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long", @EndText
The Ashened, twilight sky blankets the asylum grounds.
The grounds seem to be alive with the essence of supernatural
evil. The trees, animals and even the very earth seem to be against
all who tred here. To the north you can see Grey Stone Asylum its
self.

EndText
    );
    set( "exits", ([
"south" : "grnds10",
    ]) );
}
