// Room: /d/hainan/road5.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
一条陡峭的山路,许多时候你不得不抓着山藤才能爬上去,这时候,
你才真正体会什么是'难于上青天了',脚下的山壁显得有些松动,如果
稍不注意,就会......
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/hainan");
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"pubu",
  "eastup" : __DIR__"jueqinya",
]));

	setup();
	replace_program(ROOM);
}
