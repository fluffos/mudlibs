/*
* FILE: path1.c
* DESC: Outside the entrance to the underwater city
*/

#include <mudlib.h>
#include "ocean.h"

inherit ROOM;

void init()
{
 add_action("climb_up", "climb");
}

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
  set( "smell", "You faintly smell burning flesh.\n" );
  set( "short", "A narrow path" );
  set( "long", wrap( 
"You stand narrow path heading towards"+CITY_NAME+". "+
"A large tower is here."
  ));

 set("item_desc", ([
      "city" : "Off in the distance you see the sunken city of"+CITY_NAME+"\n",
      "R'lyeh" : "Off in the distance you see the sunken city of"+CITY_NAME+"\n",
      "path" : "You stand on a stone path.\nthe path is narrow and north towards the city of"+CITY_NAME+"\n",
      "narrow path" : "You stand on a stone path.\nThe path is narrow and north towards the city of"+CITY_NAME+"\n",
      "stone" : "The stone is worn from much travel.\n",
      "tower" : "A large tower stands next to the path.\nA ladder leads up to an observation deck.\n",
      "ladder" : "The ladder is fastened securely to the tower and leads up to an observation deck.\n",
      "sky" : "The sky made of a massive glass dome.\nBeyond that is the ocean.\n",
      "dome" : "A massive glass dome encases this undersea land.\n",
      "glass" : "The glass is very thick to prevent the ocean above from flooding in.\n",
 ]));

 set( "exits", ([
   "south" : O_ROOM+"path1",
   "north" : O_ROOM+"path3",
 ]) );
}


int climb_up(string arg)
{
  if(!arg)
  {
    write("Climb what?\n");
    return 1;
  }
  switch(arg)
  {
  default : 
    write("Are you fucking high?\n");
    return 1;
  break;
  case "ladder" :
    write("You climb up the rusty ladder.\n");
    say(this_player()->query("cap_name")+"climbs up the rusty ladder.\n");
    this_player()->move(O_ROOM+"tower");
    return 1;
  break;
  case "tower" :
    write("Your life might be a bit simpler if you used the ladder dumbass.\n");
    return 1;
  break;
  }
}

