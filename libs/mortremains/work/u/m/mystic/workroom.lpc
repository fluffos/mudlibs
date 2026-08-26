
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
  set( "short", "A workroom" );
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
This is a temporary workroom for those wizards
who do not have one of their own that will load.
EndText
  );
  set( "exits", ([
    "start" : START,
    "void"  : VOID,
  ]) );
}
