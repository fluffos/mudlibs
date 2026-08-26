#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
set( "short", "ROOM NAME HERE" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long", @EndText

The main open area of the old police station is in shambles.
Desks are over turned and their contents have spilt out apon
the ground. The lights flicker and buzz as a weak electrical
current tries to make its way to its destination. To the left is 
the captian's office and to the north is a door.
EndText
    );
    set( "exits", ([
    ]) );
}
