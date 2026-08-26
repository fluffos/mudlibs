/*
// This file contains the code for a generic workroom.
// It is used by _home.c if your own workroom won't load.
// It is used by _sponsor.c to provide new wizards
//   with a basic home that they can edit to their own taste.
*/

// config.h only included here for the defines of START and VOID
// it doesn't need to be included in most rooms.
#include <config.h>
#include <mudlib.h>

inherit PRIVATE_ROOM;

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
  set( "short", "Nemar workroom" );
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
This is the home of the biggest computer geek of all time.  You see at least 6
separate computers running around the walls of this now very cramped
room.  They all appear to be linked together and running.  You notice that
the screens are always changing.  One computer appears to be running
som sort of hacking program.  Another one appears to be downloading
a HUGE file at far above the normal speed.
All around you, you can here the constand buzzing and chirping sound of
VERY busy computers.
EndText
  );
  set( "exits", ([
    "start" : START,
    "void"  : VOID,
  ]) );
  set( "item_desc", ([
    "computers" : "You see 6 separate computers.  Perhaps you could look at a particular one.\n",
    "computer1" : "It appears to be running a hacking program.  One you have never seen before.\n",
    "computer2" : "You notice that it is downloading a HUGE file at FAR above the normal speed.\n",
    "computer3" : "You see that it is running the newest version of Quake.   Quake 38.\n",
  ]) );
}
