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
set("short","A van down by the river");
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
This is a scuzzy yet rather cozy looking van situated on
the banks of some nameless river. The decorations are 
scant but there is a little. A small cot to sleep on, and
some fuzzy dice hanging from the rear view mirror stick
out in your mind as you look around. There is also a small fridge
but you have no idea how it is powered. The van doesn't 
appear to have moved in quite some time and you think it likely
that it won't ever move again.
EndText
  );
  set( "exits", ([
    "start" : START,
    "void"  : VOID,
  ]) );
}
