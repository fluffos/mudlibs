// Room: /d/jindezheng/yuanzi.c

inherit ROOM;

void create()
{
	set("short", "院子");
	set("long", @LONG
这是一个大园,两边都是库房,有许多人正忙活着从房中往外一捆一 
捆的搬出各中瓷器,还有些人不断的把搬出的瓷器装到就近的骡马车上, 
但更多的却是挑了一担担的东西,从后院门走了出去. 
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jindezheng");
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"matou",
  "out" : __DIR__"china-shop",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tiaofu.c" : 2,
]));

	setup();
	replace_program(ROOM);
}
