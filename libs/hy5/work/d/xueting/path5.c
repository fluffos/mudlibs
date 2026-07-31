// Room: /d/green/path5.c

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
这是一条平整的石板路, 上面可以看见两道很深的车轮，看来
是用来作运输用途的道路。往北是一条较小的碎石路通往村内。东
边有一栋石屋，旁边的空地堆了一些石料。南边看去是一片矮树丛。
石板路往西边延伸。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
//"north" : "/u/girlvillage/villagepath0",
  "west" : __DIR__"path6",
  "south" : __DIR__"diaoyuchi",
  "east" : __DIR__"work",
]));
	set("no_clean_up", 0);
	set("outdoors", "xueting");
	setup();
	replace_program(ROOM);
}
