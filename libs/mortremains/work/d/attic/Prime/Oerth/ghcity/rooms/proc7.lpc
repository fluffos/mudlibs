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
The Old City. You come to a major intersection
with Cross Street.
EndText
  );
  set( "exits", ([
"north" : Oerth+"/rooms/proc8",
"south" : Oerth+"/rooms/proc6",
"east" : Oerth+"/rooms/crossstreet1",
"west" : Oerth+"/rooms/crossstreet2",
  ]) );
}
