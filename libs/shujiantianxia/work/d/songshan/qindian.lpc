// Room: qindian.c
// Created by Numa 1999-11-21

#include <ansi.h>
#include <wanted.h>
inherit ROOM;

void create()
{
	set("short", HIC"寝殿"NOR);
	set("long", @LONG
这里是嵩山派弟子的休息之所，每天清晨，弟子们都会去峻极宫外
旷地修习武艺。南北两边分别是男，女弟子的休息室，再往东就是嵩山
掌门左冷禅的卧室。
LONG);
	set("exits", ([ 
		"north" : __DIR__"nv-room",
		"south" : __DIR__"nan-room",
		"east" : __DIR__"zmwshi",
		"west" : __DIR__"suishilu3",
	]));
	set("objects", ([ 
		CLASS_D("songshan") + "/gao" : 1,
	]));
	set("outdoors", "嵩山");
	setup();
}

int valid_leave(object me, string dir)
{
	if ((dir == "north" || dir == "south") && is_wanted(me))
		return 0;

	//if ((dir == "north" || dir == "south") && me->query("quest"))这个quest表示什么? 注释by linux
		//return 0;

	if (dir == "south" && me->query("gender") == "女性")
		return notify_fail("你打开门正要往里走，忽然发现里面都是光膀子的男弟子，你赶忙捂着脸退了出来。\n");


	if (dir == "north" && me->query("gender") != "女性")
		return notify_fail("你打开门正要往里走，却听到里面传来一阵女弟子的尖叫声，你吓得赶忙退了出来。\n");

	return ::valid_leave(me, dir);
}
