#include <config.h>
#include <mudlib.h>
#include "oerth.h"

inherit ROOM;

void create()
{
  ::create();
   // Inspiral fears Root euid.  94-08-18
  seteuid( 0 );
  set( "light", 1 );
   set( "short", "The Processional" );
  set( "long", @EndText
Your travelling down The Processional through
The Old City. To the west is another road,
Old Lane. While The Processional continues
north and south. To the east is a Temple.
EndText
  );
  set( "exits", ([
"north" : Oerth+"/rooms/proc5",
"south" : Oerth+"/rooms/proc3",
"east" : Oerth+"/rooms/olidammara1",
"west" : Oerth+"/rooms/oldlane1",
  ]) );
}
