// Room: /d/japan/zoulang.c

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
你现在走在一条走廊上面,在走廊的一边是屋子,另一边是一座小小
的花园,支撑起走廊的柱子都是巨大的原木,没有经过任何的装饰,却使人
觉得十分庄重.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"liusheng",
  "southeast" : __DIR__"zoulang",
  "northdown" : __DIR__"xuanguan",
]));

	setup();
	replace_program(ROOM);
}
