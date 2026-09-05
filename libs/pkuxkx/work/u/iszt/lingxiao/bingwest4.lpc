//吴起
///d/lingxiao/bingwest4.c
//03-5-20

#include <room.h>;
#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", HIW"冰雪楼"NOR);
	set("long", @LONG
这是一家酒楼，整个楼面以冰雪为特色，不仅装饰用的是冰雪，连招牌菜都
和冰、和雪有关。至于是什么，自己问问小二吧。听说这里负责着整个凌霄城的
一半饮食原料供应，再加上平时堂上开张，生意可是不小。
LONG);
	
	set("indoors", "凌霄城");
	set("no_sleep_room", 1);
	set("exits", ([
		"east" : __DIR__"bingjie4",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));

	setup();
}

