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
    set( "short", "Brie's little hole." );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set("c_long", @EndText
You can only hope there is some sort of order to the chaos before you.
It's amazing anyone can get work done in the miscellaneous piles of 
paperwork and books.  You think the walls are grey, or is that purple?
EndText
    );
    set( "exits", ([
      "start" : START,
      "void"  : VOID,
    ]) );
}
