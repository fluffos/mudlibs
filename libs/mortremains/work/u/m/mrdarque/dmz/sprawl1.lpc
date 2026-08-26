#include <config.h>
#include <mudlib.h>
#include "/u/m/mrdarque/mrd.h",

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
set( "short", "Gibbson street" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long", @EndText
The sprawl's damp and wet streets show the cold indifference that 
the DMZ has for the leeches living within it's body. Garbage and
refuse clog and choke the streets. Papers dance and twist in the 
wind only to slap moistly on lamp posts that flicker and pop.
EndText
    );
    set( "exits", ([
    ]) );
}
