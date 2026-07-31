// Room: /d/yeyangzai/chalu.c

inherit ROOM;

void create()
{
	set("short", "叉路口");
	set("long", @LONG
这儿是个叉路口，由于这儿是通往南北的要道，所以行人多了起来。西
南通往台湾大霸尖山。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "southwest" : "/d/taiwan/dabajianshan",
  "north" : __DIR__"xiaolu",
]));
	set("outdoors", "yeyangzai");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
