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
set("author", "mrdarque" );
set( "short", "Darque's living Room" );
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
The room is bare due to reconstruction.
EndText
  );
  set( "exits", ([
    "void"  : VOID,
  ]) );
set("item_desc",([
"holes" : "The holes have exposed wires sticking out of them.\n",
"wires" : "The wires are live; they sizzle and pop with charged electricity.\n",
]) );
}
