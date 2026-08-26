#include <config.h>
// config.h used to define start and void in the add exits
// this is a test
#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
  set ( "short", "Foyer" );
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
You enter a foyer to an ancient castle.  The extreme cold and harsh winds
have ravished the outside walls but the interior appears to be as pristine
as when it was inhabited by......
EndText
  );
  set( "exits", ([
    "void"  : VOID,
  ]) );
}
