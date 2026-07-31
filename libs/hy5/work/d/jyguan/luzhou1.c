// luzhou.c 绿洲
// go town & mingjiao & tianshan
// Ver 0.1 08/14/1998 by Freeze

#include <ansi.h>
#define __RTM__        "/rtm/"
inherit ROOM;

void create()
{
	set("short",HIG "绿 洲");
	set("long",  @LONG
这个绿洲是往返于中土和西域的客商们的落脚点。
这里往东去有一个小镇，向西可以到天山。
LONG
	);	
        set("outdoors", "jyguan");


	set("exits", ([
	"west" : __DIR__"wall",
             	"east" : __DIR__"luzhou",
//                "south" : __DIR__"shanlu",
//                "north" : __DIR__"shamo",
//                "northwest" : __DIR__"shaqiu2",
//                "northeast" : __DIR__"shaqiu1",
//                "southwest" : __DIR__"shqiu2",
//                "southeast" : __DIR__"town",
	]));
	
		
	setup();
	replace_program(ROOM);
}

