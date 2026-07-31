// townroad.c 小镇路
// Town of mingjiao  
// Ver 1.0 10/8/1998 by Shark

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG "小 镇 街 道"NOR);
	set("long",   @LONG
你正走在小镇唯一的一条街道，不时有风沙袭来。西面是一家杂货铺，
东面挑出一把扫帚，定是家酒馆。
LONG
	);	
        set("outdoors", "jyguan");


	set("exits", ([
                "west" : __DIR__"zahuopu",//杂货铺
             	"east" : __DIR__"jiudian",//酒馆
                "south" : __DIR__"townroad1",
                "north" : __DIR__"town",
//                "northwest" : __DIR__"luzhou",
//                "northeast" : __DIR__"shaqiu1",
//                "southwest" : __DIR__"shqiu2",
//                "southeast" : __DIR__"town",
	]));
	
  	set("objects", ([
		"/d/shaolin/npc/tiao-fu" : 1,
        ]));
	
	setup();
	replace_program(ROOM);
}

