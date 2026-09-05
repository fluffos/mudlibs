//zhengfang.c	农家正房
//by bing

#include <room.h>
inherit ROOM;

void create()
{
	set("short","正房");
	set("long",@LONG 
这是这户农家的正房。堂上拜着一张供桌，上面
供着各位神仙和祖宗，两旁各有一支粗粗的蜡烛点着，
右面是一张饭桌，收拾得干干净净。整个屋子很洁净，
看来女主人很能干。
LONG
	);
	set("exits", ([
		"east"	: __DIR__"xiaoyuan",
		"south"	: __DIR__"wofang",
	]));
	set("objects",([
		__DIR__"obj/candle" : 2,
		__DIR__"obj/hulu" : 1,
			]));
	setup();
}

