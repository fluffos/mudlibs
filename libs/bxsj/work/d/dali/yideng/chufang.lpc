// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "斋堂");
	set("long", @LONG
这里有供全寺饮食的茶水和各种素食。整个房间飘荡着香味，一些仆役在
不停的忙着，边上一角放着好多刚摘回来的青菜。
LONG
	);
	set("no_fight", 1);
	set("exits", ([
		"east" : __DIR__"houyuan",
	]));
	set("objects", ([
		__DIR__"npc/shami1" : 1,
		FOOD_D("rice"): 2,
		FOOD_D("cha") : 2,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	object *ob = deep_inventory(me);
	int i = sizeof(ob);
	if( dir == "east" ){
		while (i--)
		if(ob[i]->id("mi fan") || ob[i]->id("xiang cha"))
			return notify_fail(CYN"小沙弥阿弥陀佛一声：「这位施主，还是在斋堂用膳吧。」\n"NOR);
	}
	return ::valid_leave(me, dir);
}
