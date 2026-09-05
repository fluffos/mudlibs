//吴起
//xuesouth5.c
//03-7-14

#include <room.h>;
#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", "当铺"NOR);
	set("long", @LONG
这是一家当铺，掌柜的却透着一股子憨厚老实劲儿。来这里做买卖的都
称赞掌柜给的价钱公道，掌柜也欢喜顾客中没有赌红了眼的赌徒。正如墙上
那对联说的：缓急人常有，权衡我岂无？
LONG);
	
	set("indoors", "凌霄城");
	set("no_fight", 1);
	set("no_get_from", 1);
	set("no_sleep_room", 1);
	set("exits", ([
		"north" : __DIR__"xuejie5",
	]));
	set("objects", ([
		__DIR__"npc/skpawn" : 1,
	]));

	setup();
}

