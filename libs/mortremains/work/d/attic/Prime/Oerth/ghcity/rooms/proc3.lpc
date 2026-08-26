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
The Old City. To the west in the Nightwatchmen
Headquarters here in the old part of town. The
road continues north and south.
EndText
  );
  set( "exits", ([
"north" : Oerth+"/rooms/proc4",
"south" : Oerth+"/rooms/proc2",
"west" : Oerth+"/rooms/nightwatchhq",
  ]) );
}
