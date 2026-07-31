// Room: /d/yanjing/street4.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
街道两边的招牌林立,行人如潮,但多是在附近交易的商人,北边老大
一座府第,乃是赵王府,几个艺人大声吆喝着在卖跌打损伤丸药.向南可以
出城.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"tiejiang",
  "south" : __DIR__"street1",
  "north" : __DIR__"wangfu",
]));
	set("outdoors", "yanjing");

	setup();
	replace_program(ROOM);
}
