// Room: /d/heifeng/mishi2.c

inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
这是一间密室。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"midao4",
]));
	set("objects", ([
		"/clone/money/gold" : 1,
		"/clone/money/silver" : 10,	
		"/d/qianjin/npc/funu" : 2,
	]));
	setup();
}
