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
set("short", "Cross Street");
  set( "long", @EndText
This is Cross Street. The only major intersection
in the Old City.
EndText
  );
  set( "exits", ([
"east" : Oerth+"/rooms/proc7",
"west" : Oerth+"/rooms/crossstreet4",
  ]) );
}
