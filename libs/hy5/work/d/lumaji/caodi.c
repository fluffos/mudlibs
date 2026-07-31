// Room: /d/lumaji/caodi.c

inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"lu4",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}