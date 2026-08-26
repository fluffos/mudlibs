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
The Old City. You come to an intersection with
The Processional heading north and south, while
Black Lane heads off to the east.
EndText
  );
  set( "exits", ([
   "north" : Oerth+"/rooms/proc2",
   "south" : Oerth+"/rooms/highgate",
   "east" : Oerth+"/rooms/blane1",
  ]) );
}
