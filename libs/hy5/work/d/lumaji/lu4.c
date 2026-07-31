// Room: /d/lumaji/lu4.c

inherit ROOM;

void create()
{
	set("short", "碎石小径");
	set("long", @LONG
一条碎石铺成的小路，中间长着一些杂草。路的左边是一家
小杂货店，右边是一片草地。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"zahuo",
  "south" : __DIR__"lu5",
  "north" : __DIR__"lu3",
  "east"  : __DIR__"caodi1",
]));
	set("objects", ([
		"/clone/npc/man" : 2,
	]));

	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}