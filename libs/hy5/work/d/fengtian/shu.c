// Room: /d/fengtian/shu.c

inherit ROOM;

void create()
{
	set("short", "书房");
	set("long", @LONG
这是一间不错的书房。房中的书并不多。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jjf5",
]));

	setup();
	replace_program(ROOM);
}
