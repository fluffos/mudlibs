// Room: /d/fengtian/minju.c

inherit ROOM;

void create()
{
	set("short", "民居");
	set("long", @LONG
这是一间什麽也没有的空房间。原先的主人逃荒去了。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xiang1",
]));

	setup();
	replace_program(ROOM);
}
