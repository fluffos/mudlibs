// Room: /d/heifeng/corr08.c

inherit ROOM;

void create()
{
	set("short", "半山小路");
	set("long", @LONG
曲折的小路盘山而上，周围丛生的树林之间夹杂着一些下雨
时滚落的石头。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"lin2",
  "south" : __DIR__"corr07",
  "north" : __DIR__"shanquan",
]));

	set("outdoors", "heifeng");

	set("objects",([
	__DIR__"npc/xunzhai" : 2,
	__DIR__"npc/toumu" : 1,
]));

	setup();
	replace_program(ROOM);
}
