#include <config.h>
#include <mudlib.h>
#include "oerth.h"

inherit ROOM;

void create()
{
  ::create();
   // Inspiral fears Root euid.  94-08-18
   seteuid(getuid());
   reset();
  set( "light", 1 );
set("short" , "The Battlements" );
  set( "long", @EndText
Your standing upon the walls surrounding the City
of GreyHawk. You can get a decent view of the city
from this vantage point and for the area surrounding
the city.
EndText
  );
  set( "exits", ([
"southwest" : Oerth+"/rooms/watchtower2",
"northeast" : Oerth+"/rooms/battlement11",
  ]) );
}
