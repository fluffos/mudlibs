// Room: /d/lumaji/shutang.c

inherit ROOM;

void create()
{
	set("short", "书堂");
	set("long", @LONG
这里是村里唯一教书识字的地方。教书先生以前是个商户，
由于败落才到这里来教书。村里的人都没什么文化，所以先生也
只教一些简单的东西，因此收费也很低。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lu8",
]));
	setup();
	replace_program(ROOM);
}
