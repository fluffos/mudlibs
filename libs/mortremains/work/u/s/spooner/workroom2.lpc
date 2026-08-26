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
  set( "short", "A workroom" );
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
You have entered the Great Room to Spooner the Great!!  His desk looks very messy and it is 
obvious that he is very busy at the present time, I would not touch anything on his desk or he would
forsurely lose it!!  He hope's that you enjoy his room a..
EndText
  );
  set( "exits", ([
    "start" : START,
    "void"  : VOID,
  ]) );
}
