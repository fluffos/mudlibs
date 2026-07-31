// Room: /d/heifeng/mishi1.c

inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
这是一间密室。
LONG
	);

	set("objects", ([
		"/clone/money/gold" : 1,
		__DIR__"npc/chick" : 1,
	]));

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"midao2",
]));

	setup();
}
