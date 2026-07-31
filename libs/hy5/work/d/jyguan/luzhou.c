// luzhou.c 绿洲
// go town & mingjiao & tianshan
// Ver 0.1 08/14/1998 by Freeze

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG "绿 洲");
	set("long",  @LONG
在这茫茫沙漠里突然看见这个绿洲真是令人兴奋不已，连路的疲惫似乎顷刻间
散去。这里往东南方向是一个小镇，向西就可以到天山了。
LONG
	);	
        set("outdoors", "jyguan");


	set("exits", ([
		"west" : __DIR__"luzhou1",
//              	"east" : __DIR__"shamo",
//                "south" : __DIR__"shanlu",
                "north" : "/d/suiye/caoyuan",
                "northwest" : __DIR__"shaqiu2",
//                "northeast" : __DIR__"shaqiu1",
//                "southwest" : __DIR__"shqiu2",
                "southeast" : __DIR__"town",
	]));
	
		
	setup();
	replace_program(ROOM);
}

