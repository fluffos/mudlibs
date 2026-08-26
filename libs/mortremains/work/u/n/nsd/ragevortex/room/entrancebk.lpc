/*
** File: entrancebk.c
** Author: Ragevortex
** Updated by: Lady Nsd (august 2000)
*/

#include <config.h>
#include <mudlib.h>
#include "mina.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set( "short", "Entrance to the Minotour's lair" );
    set("author", "ragevortex");
    set( "long", @EndText
You stand in a cold metal room. There are several warnings posted
on the walls. The metal walls seem to be covered with scratches
and dents. There are stains on the floor and walls.
EndText
    );
    set( "exits", ([
      "start" : START,
      "void"  : VOID,
    ]) );
    set("item_desc", ([
      "warning" :
      "WARNING, DO NOT ENTER! This leads to the lair of the minotaurs.\n",
      "warnings" : "Most of them seem unreadable but there's one warning\n"+
      "you can examine here.\n",
      "stains" : "Nothing but dry blood... the metal around them is rusted.\n",
      "scratches" : "Although they are solid, something was able to scratch"+
      " them.\n",
      "dents" : "They look like something was smashed rather solidly here.\n",
      "teleporter" : "A pannel on a corner that glows with crackling energy.\n"+
      " It says 'Teleporter' in flashy letters.\n",
    ]) );
}
