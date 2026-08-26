/*
* FILE: seacave.c
*/

#include <mudlib.h>
#include "ocean.h"

inherit ROOM;

void init()
{
    //add_action("subroutine", "command");
}

void create()
{
    ::create();
    seteuid( getuid() );
    set("author" , "herself");
    set( "light", 1 );
    set("smell" , "The smell of fish invades your senses. \n");
    set("short" , "A Cave");
    set( "long", wrap( 
	"You stand in a small cave, hidden deep under the sea. "+
	"The walls of the cave are coral, and swarming with "+
	"sealife. The only light source comes from a small "+
	"crack in the far wall. "
      ));

    set("item_desc", ([
      "cave#small cave" : "You are inside the cave. \n",
      "coral#walls#wall" : "The cave seems to be carved out of coral. \n",
      "sealife" : "Tiny animals dwell in and on the coral. \n",
      "crack#small crack" : "Just wide enough for you to slip through.\n",
      "sea#water#ocean" : "Water is all around you. \n",
    ]));

    set( "exits", ([
      "up" : O_ROOM+"deep_sea",
      "crack" : O_ROOM+"tunnel1",
    ]));

}
