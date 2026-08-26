/*
* FILE: Magog01.c
* DESC:
*/

#include <mudlib.h>
#include "ocean.h"

inherit ROOM;

void init()
{
  //add_action("subroutine", "command");
}

void create()
{
  ::create();
  seteuid( getuid() );
  set("author", "gasman");
  set( "light", 1 );
  set( "smell", "" );
  set( "short", "Rue Magog" );
  set("long", wrap(
"You are standing on the west end of Rue Magog. "+
"The road ends here right at the dome. Through the glass "+
"you can see the deep dark ocean.\n"
 ));

 set("item_desc", ([
      "dome" : "A massive glass dome encases this undersea land.\n",
      "glass" : "The glass is very thick to support the ocean's weight.\n",
      "ocean" : "The ocean is almost pure black down here. Occasionally a glow fish swims by.\n",
 ]));

  set( "exits", ([
    "east"  : O_CITY+"magog02",
  ]));
}

