/*
* FILE: Magog02.c
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
"To the south is the \"Monk Jazz Bar\" with a sign on the out side.\n"
  ));

 set("item_desc", ([
      "dome" : "A massive glass dome encases this undersea land.\n",
      "pub"  : "The Monk Jazz Bar.\n A premiere jazz night club.\n",
      "sign" : "It reads: Live Jazz!\n",
 ]));

  set( "exits", ([
    "east"  : O_CITY+"magog03",
    "west"  : O_CITY+"magog01",
    "south"  : O_CITY+"monk_bar",
  ]));
}

