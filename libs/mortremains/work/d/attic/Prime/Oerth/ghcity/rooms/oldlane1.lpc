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
set("short", "Old Lane");
  set( "long", @EndText
This is Old Lane, it travels through the less
populate section of The Old City.
EndText
  );
  set( "exits", ([
"east" : Oerth+"/rooms/proc4",
"west" : Oerth+"/rooms/oldlane2",
  ]) );
}
