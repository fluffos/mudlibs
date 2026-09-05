// Room: /u/cuer/emei/xiaojin3.c

inherit ROOM;

void create()
{
	set("short", "小径");
set("outdoors","emei");
	set("long", @LONG
这是一条曲径通幽的小道，两边是翠竹成行，耳中可
以听闻到悦耳的鸟鸣。一条小溪伴在小路的傍边，前方就
是著名的九老洞了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"xiaojin2",
  "west" : __DIR__"jldong",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
