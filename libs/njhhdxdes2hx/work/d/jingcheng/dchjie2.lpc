#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"东长安街"NOR);
	set("long", @LONG
你走在一条宽阔的石板大街上，西面就快到城中心了，东面是东长
安街和白虎大街的十字路口。路北是一家规模不小的宅院，院门的
牌匾上写着斗大的“振远镖局”。
LONG
	);

	set("exits", ([
 "west" :__DIR__"dchjie1",
 "east" :__DIR__"dchjie3",  
 "north" :__DIR__"biaoju1",
 "south" :__DIR__"yizhan",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

