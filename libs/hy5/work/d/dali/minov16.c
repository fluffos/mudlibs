//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "农田");
	set("long", @LONG
这里已经是平原的尽头，对面就是险峻的山岭了，一些的农田和
罗伽部村民的房屋零星地分布在山脚下，一些村民正在田里耕作。有
条道路向东南的山上蜿蜒而去。
LONG
        );

	set("exits", ([
		"west" : __DIR__"minov13",
		"southeast" : __DIR__"minov17",
		]));

	set("objects", ([
		__DIR__"npc/bynong.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
