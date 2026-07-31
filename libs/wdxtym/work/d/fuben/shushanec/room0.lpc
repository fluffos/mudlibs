// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", HIC"天幕"NOR);
	set("long", @LONG
这里是禁地的入口，其结构自成迷宫，度过此关者可入剑宫寻求剑灵加持自身！
LONG
	);
	set("no_fly",1);
	set("exits", ([
		"east" : __DIR__"room1",
		"north" : __DIR__"a",
		"west" : __DIR__"room2",
		"south" : __DIR__"enter",
	]));
	set("objects", ([
   __DIR__"npc/a1":3,
	]));
	setup();
}

