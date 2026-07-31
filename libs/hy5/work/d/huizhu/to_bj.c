// Room: /d/huizhu/to_bj.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这是条连接京城与嘉峪关的官道，西边通往嘉峪关，东边不远就是兰州
城了。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "huizhu");
	set("exits", ([ /* sizeof() == 2 */
  "east" : "/d/lanzhouchen/jincheng",
  "southwest" : __DIR__"guandao4",
]));

	setup();
	replace_program(ROOM);
}
