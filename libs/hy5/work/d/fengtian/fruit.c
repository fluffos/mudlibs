// Room: /d/fengtian/fruit.c

inherit ROOM;

void create()
{
	set("short", "水果店");
	set("long", @LONG
康定路的确是盛京的老街，您看这水果店都有年头了，老店
别看扑面不是特别好，但是买的水果可是北方少有的，门口牌子
上写着每种水果的价格。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"kd3",
]));

	setup();
	replace_program(ROOM);
}
