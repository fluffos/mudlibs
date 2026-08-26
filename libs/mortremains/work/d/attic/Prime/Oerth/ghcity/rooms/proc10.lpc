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
The Old City. To the west is a road called
Assassins End. To the east is a boarding 
house, and directly to the north is
Black Gate.
EndText
  );
  set( "exits", ([
"north" : Oerth+"/rooms/blackgate",
"south" : Oerth+"/rooms/proc9",
"west" : Oerth+"/rooms/assassinend1",
"east" : Oerth+"/rooms/boardinghouse",
  ]) );
}
