// by xiaoyao

#include <room.h>

inherit ROOM;
void create()
{
        set("short", "永登");
        set("long", @LONG
这里就是西北的军事重镇永登。一座孤城耸立在茫茫荒野之上。此城建于
汉光武年间，据闻大将军霍去病曾在此练兵三年，后一举平定大西北。历代而
来，这里都有军队长驻。
LONG );
	set("exits", ([
		"northwest"   : __DIR__"xjqiao",
//		"east"    : __DIR__"huanghe_3",
		"west"    : __DIR__"kedian",
		"east" : __DIR__"road4",
        ]));
        set("objects", ([
		__DIR__"npc/wujiang1" : 1,
		__DIR__"npc/bing1" : 2,
	]));
	set("outdoors", "兰州");
	setup();
}

