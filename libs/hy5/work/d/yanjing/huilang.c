// Room: /d/yanjing/huilang.c

inherit ROOM;

void create()
{
	set("short", "回廊");
	set("long", @LONG
朱红的柱子间是一盏盏小巧的玻璃宫灯,廊外就是小巧的花园,一路
走来,亭台楼阁,假山流水,小桥枯藤,美不胜收,回廊转角处,一座小巧画
楼挑起,却正抵着下面的青青果树.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"huilang1",
  "east" : __DIR__"qianting",
]));
	set("no_clean_up", 0);
	set("outdoors", "yanjing");

	setup();
	replace_program(ROOM);
}
