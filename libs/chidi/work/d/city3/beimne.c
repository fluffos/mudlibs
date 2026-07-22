// Room: /chengdu/northchengmen.c
// oooc: 1998/06/27 

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "北门");
	set("long", @LONG
成都北门，这年头天下不太平，再加上成都是蜀中重镇，是
兵家守卫之要冲，自然是盘查严密。厚厚青砖叠起的城墙上爬满
了青藤，也不知究竟有多少个年头了。守城的兵勇不怀好意的瞪
着你，在此徘徊显也易见不是什么好事，你不由得加快了步伐。
道路南北纵横。
LONG
	);

	set("exits", ([
                "north" : __DIR__"dadao",
                "south" : __DIR__"beijie",
	]));
        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
        ]));
        set("outdoors", "chengdu");
	setup();
}

