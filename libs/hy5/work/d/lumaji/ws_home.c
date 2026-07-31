// Room: /d/lumaji/ws_home.c

inherit ROOM;

void create()
{
	set("short", "王生家");
	set("long", @LONG
这里是村民王生的家，屋里土坑上有一位上年纪的老妇卧在
床的里面，那是王生久病的母亲。屋里东西很少，一看就知道这
家很穷。王生考举未中，现在只得打柴为生。偶尔有村民找他帮
写几个字，对他来说，也是一笔可观的收入。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"lu15",
]));

	setup();
	replace_program(ROOM);
}
