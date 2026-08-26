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
  seteuid( getuid() );
  set( "light", 1 );
set( "short", "Kekorka's home" );
// NB: "@EndText" should not have spaces after it.
// "EndText" should be on a line of its own (no indentation, tabs or spaces)
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
The twisted objects in this room give you but a glimps into Kekorka's insanity
The cold draft sends a chill down your spine. Coming in here was a bad idea
The disimbodied head of a Tanar'ri does not help to comfert you.
EndText
  );
  set( "exits", ([
    "start" : START,
    "void"  : VOID,
  ]) );
}
