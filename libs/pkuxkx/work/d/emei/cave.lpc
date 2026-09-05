// Room: /u/cuer/emei/cave.c

inherit ROOM;

void create()
{
	set("short", "洞穴");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"didao1",
  "out" : __DIR__"fhuang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
