// Room: /u/wsl/changan/ca3.c
// This is a room made by wsl.

inherit ROOM;

void create()
{
	set("short", "酒店二楼");
	set("long", @LONG
上到客店的二楼，你不觉增添了一丝困意，与东厢房吧，西厢房
已经有人住了。听说是有个书生一直住在那的。
LONG
);
        set("exits", ([
  "west" : __DIR__"ca5",
  "down" : __DIR__"ca2",
  "east" : __DIR__"ca4",
]));

	setup();
	replace_program(ROOM);
}
