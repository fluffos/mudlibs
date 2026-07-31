// Room: /d/fengtian/wy3.c

inherit ROOM;

void create()
{
	set("short", "威远路");
	set("long", @LONG
威远路是一条东西向的大街，也是盛京主干道，大街东西贯
通，街道也相当宽阔，这两年天下比较太平，新上任不久的盛京
府尹就派人把旧路扩宽了，这里向东是个十字路口。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"bank",
  "west" : __DIR__"wy2",
  "east" : __DIR__"cross",
  "north" : __DIR__"wuguan",
]));
        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
