// Room: /d/yandang/luoyan26.c

inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
这是一片草坪,上面的青草柔柔的,仅漫过脚背,走在上面,实在是
一种享受,在草坪的尽头,有一栋小小的楼阁,如佳人凌世而独立,只是
站在那里,就给你无限的想象.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"luoyan25",
  "north" : __DIR__"luoyan27",
   //"west" : "/u/legato/yueliangmen",
]));

	setup();
	replace_program(ROOM);
}
