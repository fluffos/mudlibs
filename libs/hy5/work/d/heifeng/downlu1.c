// Room: /d/heifeng/downlu1.c

inherit ROOM;

void create()
{
	set("short", "下山小路");
	set("long", @LONG
这是一条通下山的小路。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "westup" : __DIR__"shanding",
]));

	setup();
	replace_program(ROOM);
}
