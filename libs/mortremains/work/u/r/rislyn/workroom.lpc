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

inherit ROOM;

void create()
{
  ::create();
   // Inspiral fears Root euid.  94-08-18
  seteuid( 0 );
  set( "light", 1 );
  set( "short", "A workroom" );
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
This is a stone room, brightly light by torchlight[D[D[D[D[D[D[D[D[D[D[D[D[D[D[D[C[C[C[C[C[C[C[C[Ct by torchlight. A
smooth wooden table stands against one wall. A fierce
stone dragon on the far wall stares out across the room
with gleaming saphire eyes, protecting the room.
EndText
  );
  set( "exits", ([
    "start" : START,
    "void"  : VOID,
  ]) );
}
