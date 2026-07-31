// Room: /d/taohua/taijie2.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这里是一条小路曲曲折折，有时路似已断，但
忽然一转，又是柳暗花明。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
   "north" : __DIR__"taijie3",
  "south" : __DIR__"taijie1",
]));
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
