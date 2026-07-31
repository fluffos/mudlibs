// Room: /d/menggu/huanglu1.c

inherit ROOM;

void create()
{
	set("short", "荒路");
	set("long", @LONG
这是条连接关内外的荒路，由于远离城镇，人烟稀少。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "menggu");
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : "/d/guanwai/road8",
  "northwest" : __DIR__"damo2",
]));

	setup();
	replace_program(ROOM);
}
