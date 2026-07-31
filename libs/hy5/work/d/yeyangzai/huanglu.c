// Room: /d/yeyangzai/huanglu.c

inherit ROOM;

void create()
{
	set("short", "荒路");
	set("long", @LONG
这条小路上荒无人烟，除了风声就是树上乌鸦的叫声。西面是个叉路口，
往北就是「野羊寨」的大门。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"huangye",
  "north" : __DIR__"men",
]));
	set("outdoors", "yeyangzai");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
