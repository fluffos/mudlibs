// Room: /open/dt/shuiguodian.c

inherit ROOM;

void create()
{
	set("short", "水果店");
	set("long", @LONG
大同的水果店里的水果并不像关内的水果店那样花色齐全，
这里一般只卖一些本地的和关外出产的果品，因为从关内将水果
运到此地要花费很多的金钱，而且这里气候干燥，水果运来也保
存不久，不过由于此地土壤多为沙质，所以这里盛产的苹果却十
分甘甜多汁。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"jinyangjie2",
]));

	set("objects",([
	__DIR__"npc/fruit_seller" : 1,
]));

	setup();
	replace_program(ROOM);
}
