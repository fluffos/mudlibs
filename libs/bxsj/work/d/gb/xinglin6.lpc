// Room: /gaibang/xinglin.c
// by pishou
// Lklv modify 2001.9.27

inherit ROOM;

void create()
{
	set("short", "杏子林");
	set("long", @LONG
这是一片杏子林，一走进来，你仿佛迷失了方向。你在杏花丛乱闯, 试图
发现出林的路。杏树上的鲜花开得缤纷绚丽，简直分不出方向，放眼望去，到
处都是盛开的鲜花。
LONG
	);
	set("outdoors", "苏州");

	set("exits", ([
		"east" : __FILE__,
		"west" : __DIR__"xinglin7",
		"south" : __DIR__"tianjing",
		"north" : __FILE__,
	]));
	set("objects", ([
                CLASS_D("gaibang/qnqigai") : 1,
	]));

	setup();
}
