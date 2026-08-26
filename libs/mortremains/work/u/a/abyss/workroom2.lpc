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
    set("author","abyss");
    set( "light", 1 );
    set( "short", "The Abyss" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long", @EndText
You seem to be falling in what seems to be "The Abyss" but you are not sure.
The room is pitch black except for the faint light coming from your
imagination of what the room looks like.  There is a desk in what seems to 
be the corner, and on the side of it there is a cooler with some assorted
sodas in it(you can barely make out what seems to be a few bottles of Corona
underneeth all the soda). There are a few chairs scattered around the
room.  On some are magazines, books, cards, and pets.  The others are free
for you to sit in.  Now that your eyes have adjusted to the dim light you
can barely make out some pictures of family and pets.  There is a sign
that reads "DO NOT DISTURB ME IF I AM WORKING!!"
EndText
    );
    set( "exits", ([
      "start" : START,
      "void"  : VOID,
    ]) );
    set( "short", "The Abyss" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long", @EndText
You seem to be falling in what seems to be "The Abyss" but you are not sure.
The room is pitch black except for the faint light coming from your
imagination of what the room looks like.  There is a desk in what seems to 
be the corner, and on the side of it there is a cooler with some assorted
sodas in it(you can barely make out what seems to be a few bottles of Corona
underneeth all the soda). There are a few chairs scattered around the
room.  On some are magazines, books, cards, and pets.  The others are free
for you to sit in.  Now that your eyes have adjusted to the dim light you
can barely make out some pictures of family and pets.  There is a sign
that reads "DO NOT DISTURB ME IF I AM WORKING!!"
EndText
    );
    set( "exits", ([
      "start" : START,
      "void"  : VOID,
    ]) );
}
