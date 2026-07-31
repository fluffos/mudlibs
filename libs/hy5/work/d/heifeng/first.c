// Room: /d/heifeng/first.c

inherit ROOM;

void create()
{
	set("short", "大寨主居室");
	set("long", @LONG
这里就是大寨主居室。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"xiaolu2",
]));
	set("objects", ([
		"/clone/npc/npc1" : 1,
	]));
	setup();
	replace_program(ROOM);
}
