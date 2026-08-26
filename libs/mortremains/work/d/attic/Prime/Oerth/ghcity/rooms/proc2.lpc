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
The Old City. To the west is the Gold Digger Tavern
and to the east you'll find the Brass Dragon Inn.
The road continues north and south.
EndText
  );
  set( "exits", ([
   "north" : Oerth+"/rooms/proc3",
   "south" : Oerth+"/rooms/proc1",
   "west" : Oerth+"/rooms/golddigger",
   "east" : Oerth+"/rooms/brassdragoninn",
  ]) );
}
