#include "path.h"
inherit CITYROOM;

#define NUM 1

setup()
{
 set_light(100);
 set_short("Wall Street");
 set_long(
"You are on Wall street.  The street continues to the east and west.\n"+
"To the north you the back of the barracks of the militia. If one "+
"is to believe rumours the room where the fighters discuss things is "+
"right at the other side of this barracks wall.\n"); 

 add_exit("east", ROOM+"tower1", "road");
 add_exit("west", ROOM+"wall3", "road");
/*
 add_exit("down", ROOM+"uway1", "road");
 modify_exit("down", ({"function", "go_ud"}) );
*/
 add_alias("barracks", "wall");
 add_alias("barracks wall", "wall");
 add_item("wall",
"There are some cracks in the barracks wall, but other than that it seems to "+
"be a quite ardinary wall.\n");
 add_alias("crack", "cracks");
 add_item("cracks", "Through the cracks in the wall you can barely make out "+
  random(4)+" fighters discussing something.\n");
 add_alias("fighter", "fighters");
 add_item("fighters", "Just some fighters discussing something. Stupid huh, "+
  "fighters discussing something. Better at mangling things they are!\n");

 set_zone("city");
 set_monster(NUM, "city");
}


