#include "path.h"
inherit CITYROOM;

#define NUM 3

setup()
{
 set_light(100);
 set_short("Wall street");
 set_long("You are on Wall street. "+
	"Wall street follows the city-walls to the south and north "+
	"to the western city gate. To the east is Market Way.\n");
 add_exit("north",ROOM+"wgate", "road");
 add_exit("south", ROOM+"wall16", "road");
 add_exit("east", ROOM+"mark2", "road");
 add_alias("city gate", "gate");
 add_alias("western city gate", "gate");
 add_item("gate",
	"The gate seems to be closed at the moment.\n");
 set_monster(NUM, "city");
 set_zone("city");
}
