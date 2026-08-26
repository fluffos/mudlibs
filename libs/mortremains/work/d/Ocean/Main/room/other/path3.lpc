/*
* FILE: path1.c
* DESC: Outside the entrance to the underwater city
*/

#include <mudlib.h>
#include "ocean.h"

inherit ROOM;

void init()
{
}

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
  set( "smell", "You faintly smell burning flesh.\n" );
  set( "short", "A narrow path" );
  set( "long", wrap( 
"You stand narrow path heading towards"+CITY_NAME+". "
  ));

 set("item_desc", ([
      "city" : "Off in the distance you see the sunken city of"+CITY_NAME+"\n",
      "R'lyeh" : "Off in the distance you see the sunken city of"+CITY_NAME+"\n",
      "path" : "You stand on a stone path.\nthe path is narrow and north towards the city of"+CITY_NAME+"\n",
      "narrow path" : "You stand on a stone path.\nThe path is narrow and north towards the city of"+CITY_NAME+"\n",
      "stone" : "The stone is worn from much travel.\n",
      "sky" : "The sky made of a massive glass dome.\nBeyond that is the ocean.\n",
      "dome" : "A massive glass dome encases this undersea land.\n",
      "glass" : "The glass is very thick preventing the ocean above from flooding in.\n",
 ]));

 set( "exits", ([
   "south" : O_ROOM+"path2",
   "north" : O_ROOM+"path4",
 ]) );
}
