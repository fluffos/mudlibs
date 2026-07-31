// Room: /d/fengtian/wy2.c

inherit ROOM;

void create()
{
	set("short", "威远路");
	set("long", @LONG
威远路是一条东西向的大街，也是盛京主干道，大街东西贯
通，街道也相当宽阔，这两年天下比较太平，新上任不久的盛京
府尹就派人把旧路扩宽了。
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"mashi",
  "west" : __DIR__"wy1",
  "east" : __DIR__"wy3",
]));

	set("objects",([
	__DIR__"npc/wuzhe" : 2,
]));

        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
