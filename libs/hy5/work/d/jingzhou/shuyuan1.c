// Room: /d/jingzhou/shuyuan1.c
// congw
inherit ROOM;

void create()
{
	set("short", "书院后院");
	set("long", @LONG
这里是书院的后院，打扫得非常干净，四周是过人的围墙，偶尔有几声鸟语，让人
觉得安静和谐，南边有一道小门，通往一片竹林。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  
  "north" : __DIR__"shuyuan",
  "south" : __DIR__"shijie",
]));
	
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
