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
The Old City. To the east is th public bath
house. Otherwise the road heads north and
south.
EndText
  );
  set( "exits", ([
"north" : Oerth+"/rooms/proc7",
"south" : Oerth+"/rooms/proc5",
"east" : Oerth+"/rooms/bathhouse",
  ]) );
}
