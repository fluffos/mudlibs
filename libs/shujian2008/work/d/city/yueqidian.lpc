// Room: /d/city/yueqidian.c

inherit ROOM;

void create()
{
	set("short", "乐器店");
	set("long", @LONG
这是一家古香古色的乐器店。四面的墙上挂满了各种奇怪的乐器，除了常
见的琴瑟笛箫外，还有许多是叫不出名字的。店老板站在柜台后面，正拿着一
支箫在比划着。东面是扬州城的月老亭，南面是品棋亭。
LONG
	);

	set("exits", ([
		"east" : __DIR__"yuelaoting",
		"south" : __DIR__"pinqiting",
		"north" : __DIR__"dongdajie3",
	]));

	set("objects", ([
		__DIR__"npc/xiao" : 1,
	]));
	set("incity",1);
	setup();
}
