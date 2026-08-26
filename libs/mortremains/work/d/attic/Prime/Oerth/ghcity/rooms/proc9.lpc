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
The Old City. To the west is the White Horse
Inn. The Processional leads north and south.
EndText
  );
  set( "exits", ([
"north" : Oerth+"/rooms/proc10",
"south" : Oerth+"/rooms/proc8",
"west" : Oerth+"/rooms/whitehorseinn",
  ]) );
}
