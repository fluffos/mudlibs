/*
* FILE: tunnel1.c
* DESC: beginning of a tunnel
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
  set( "light", 1 );
  set( "smell", "The tunnel smells musty." );
  set( "short", "A glass tunnel.");
  set( "long", wrap( 
       "You are in a glass tunnel deep under the sea. "+
       "It continues on to the east. "
  ));

 set("item_desc", ([
      "walls" : "The walls are smooth and mad out of glass. They curve forming the floor and ceiling.\n",
      "wall" : "The walls are smooth and mad out of glass. They curve forming the floor and ceiling.\n",
 ]));

  set( "exits", ([
    "east"  : O_ROOM+"tunnel3",
    "west" : O_ROOM+"tunnel1",
  ]));
}

