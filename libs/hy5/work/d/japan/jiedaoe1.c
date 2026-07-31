// Room: /d/japan/jiedaoe1.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
一条宽阔的街道,向南是一间铁匠铺子,从里面传来的叮叮当当的声
音传遍了整条街道.北面是一间当铺.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "japan");
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"jiedaoe2",
  "west" : __DIR__"zhongxin",
  "south" : __DIR__"tiejiangpu",
  "north" : __DIR__"dangpu",
]));

	setup();
	replace_program(ROOM);
}
