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
To the west is Fedroot's Daggerarium.
EndText
  );
  set( "exits", ([
"west" : Oerth+"/rooms/daggerarium",
"north" : Oerth+"/rooms/oldlane6",
"south" : Oerth+"/rooms/oldlane4",
  ]) );
}
