// Room: /gaibang/xinglin.c
// by pishou

inherit ROOM;

void create()
{
	set("short", "杏子林");
	set("long", @LONG
这是一片杏子林，一走进来，你仿佛迷失了方向。你在杏花丛乱闯, 试图
发现出林的路。杏树上的鲜花开得缤纷绚丽，简直分不出方向，放眼望去，到
处都是盛开的鲜花。南面是一个田埂。
LONG
	);
	set("outdoors", "苏州");

	set("exits", ([
		"east" : __DIR__"xinglin2",
		"west" : __FILE__,
		"south" : __DIR__"tianjing",
		"north" : __FILE__,
	]));
	setup();
}
