// Room: /d/yandang/to_yandang2.c

inherit ROOM;

void create()
{
	set("short", "大路");
	set("long", @LONG
路面开始变得不那么平整,坑坑洼洼的,两边的农田变为连绵的杂
树林,浓密的树荫遮住了人的视野,只能感觉你在向上走.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"shulin",
  "west" : __DIR__"to_yandang",
  "east" : __DIR__"to_yandang3",
]));
	set("outdoors", "/d/yandang");

	setup();
	replace_program(ROOM);
}
