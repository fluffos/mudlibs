// Room: /d/huizhu/guandao4.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这是条连接京城与嘉峪关的官道，东边是京城方向，西边通往嘉峪
关。道路的北边是片树林,一边好象有些人在注意你.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "huizhu");
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"guandao3",
  "northeast" : __DIR__"to_bj",
]));

	setup();
	replace_program(ROOM);
}
