/*
* FILE: tunnel1.c
* DESC: beginning of a tunnel
*/

#include <mudlib.h>
#include "ocean.h"

inherit ROOM;

int player_dex;

void init()
{
  //add_action("subroutine", "command");
}

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
  set( "smell", "The tunnel smells musty.\n" );
  set( "short", "A glass tunnel.");
  set( "long", wrap( 
       "You are in a glass tunnel at the base of a steep hill. "+
       "The structure has expanded to a huge dome. Off in the  "+
       "distance you can see what appers to be a city."
  ));

 set("item_desc", ([
      "walls" : "The walls are smooth and mad out of glass. They curve forming the floor and ceiling.\n",
      "wall" : "The walls are smooth and mad out of glass. They curve forming the floor and ceiling.\n",
      "dome" : "The walls of the tunnel have expanded outward, creating a massive glass dome.\n",
      "city" : "From here, you can see the faint outline of a city.\n",
 ]));

  set( "exits", ([
       "up"  : O_ROOM+"tunnel3",
       "north"  : O_ROOM+"path1",
  ]));

 set ("pre_exit_func", ([ "up" : "climb_up" ]));

}


int climb_up(string arg)
{
  player_dex = this_player()->query("stat/dexterity");
  if(player_dex < 10)
  {
    write("You attempt to climb up the glass hill, but are too clumbsy.\n");
    return 1;
  }
  else
  {
    return 0;
  }
}

