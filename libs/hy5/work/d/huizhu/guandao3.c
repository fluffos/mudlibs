// Room: /d/huizhu/guandao3.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这是条连接京城与嘉峪关的官道，东边是京城方向，西边通往嘉峪
关。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/man1.c" : 2,
]));
	set("no_clean_up", 0);
	set("outdoors", "huizhu");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"guandao2",
  "northeast" : __DIR__"guandao4",
]));

	setup();
	replace_program(ROOM);
}
