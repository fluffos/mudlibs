// Room: /d/fengtian/mashi.c

inherit ROOM;

void create()
{
	set("short", "马市");
	set("long", @LONG
这里是盛京最大的马市，有最纯种的辽东马，如果你想买坐
骑，在这里选择是个好主意，由这里出去向西可以到盛京的大西
门，向东可以是盛京的十字路口。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wy2",
]));

	set("objects",([
	__DIR__"npc/ride_s" : 1,
]));

	setup();
	replace_program(ROOM);
}
