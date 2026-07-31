// town.c 小镇
// Town of mingjiao  
// Ver 1.0 10/8/1998 by Shark

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG "小 镇"NOR);
	set("long",   @LONG
这是一个由北疆戍边将士家眷聚居而形成的小镇，在这沙漠之中人们
的生活用品都在此交易，她宛如人们心目中的一块翡翠。从这里往北就再
也没有什么人烟了。
LONG
	);	
        set("outdoors", "jyguan");


	set("exits", ([
//	          "west" : __DIR__"luzhou1",
//              	"east" : __DIR__"shamo",
                "south" : __DIR__"townroad",
//                "north" : __DIR__"shamo",
                "northwest" : __DIR__"luzhou",
//                "northeast" : __DIR__"shaqiu1",
//                "southwest" : __DIR__"shqiu2",
//                "southeast" : __DIR__"town",
	]));
	
  	set("objects", ([
                __DIR__"npc/shangren" : 1,
		"/d/shaolin/npc/tiao-fu" : 2,
                __DIR__"npc/xiao-fan" : 1,
        ]));
	
	setup();
	replace_program(ROOM);
}

