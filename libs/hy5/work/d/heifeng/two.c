// Room: /d/heifeng/two.c

inherit ROOM;

void create()
{
	set("short", "二寨主居室");
	set("long", @LONG
这里是二寨主居室。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"xiaolu1",
]));
	set("objects", ([
		"/clone/npc/npc" : 1,
	]));
	setup();
	replace_program(ROOM);
}
