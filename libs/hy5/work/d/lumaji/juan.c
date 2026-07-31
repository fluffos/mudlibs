// Room: /d/lumaji/juan.c

inherit ROOM;

void create()
{
	set("short", "马圈");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"yuan",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
