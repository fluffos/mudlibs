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
The Old City. To the east is the  common crypts,
and too the west is a fortune tellers booth. A 
small path leads northeast to a bewery.
EndText
  );
  set( "exits", ([
"north" : Oerth+"/rooms/proc9",
"south" : Oerth+"/rooms/proc7",
"west" : Oerth+"/rooms/fortunebooth",
"east" : Oerth+"/rooms/cryptentrance",
"northeast" : Oerth+"/rooms/brewery",
  ]) );
}
