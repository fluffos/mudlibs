#include <config.h>
#include <mudlib.h>
#include "rooms.h"

inherit ROOM;
object maker;


void create()
{
  ::create();
  seteuid(getuid());
  set( "light", 1 );
  set("short" , "A small jail cell");
  set( "long" , @EndText
  How the hell did you end up here? The bleak walls are dark and dank and the
  bars on the cell really don't make you feel too at home. Don't you wonder how
  you're going to get out of here? You can see 5 other cells in this room, and a
  few of them are occupied, but no one wants to talk with you...

EndText
  );
  set( "exits", ([
  ]) );
  set("item_desc" , ([
    "bars" : "Good luck trying to break these.\n",
    "cell" : "A simple cell, complete with a toilet and a bed.\n",
    "toilet" : "Actually its a hole in the gound that leads to a large 'doodie pot'...happy now?\n",
    "bed" : "To think that you have to sleep on that thing...ew.\n",
    "cells" : "Its really too dark to see anything in the other cells.\n",
    "walls" : "Dark and dank...sweaty too....kinda gross.\n",
  ]));
reset();
}
