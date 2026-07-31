// Room: /d/yanjing/huilang1.c

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
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shatongtian.c" : 1,
]));
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"huilang",
  "northwest" : __DIR__"huilang2",
  "north" : __DIR__"huayuan",
]));
	set("no_clean_up", 0);
	set("outdoors", "yanjing");

	setup();
	replace_program(ROOM);
}
