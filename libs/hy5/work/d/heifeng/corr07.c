// Room: /d/heifeng/corr07.c

inherit ROOM;

void create()
{
	set("short", "半山小路");
	set("long", @LONG
曲折的小路盘山而上，周围丛生的树林之间夹杂着一些下雨
时滚落的石头。
LONG
	);
	set("outdoors", "heifeng");

	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"lin1",
  "south" : __DIR__"corr06",
  "east" : __DIR__"shinv",
  "north" : __DIR__"corr08",
]));

	setup();
	replace_program(ROOM);
}
