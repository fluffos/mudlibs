// Room: /open/dt/lukou.c

inherit ROOM;

void create()
{
	set("short", "路口");
	set("long", @LONG
这是紧靠着南门的一个路口，由于被重重楼房所阻，漫天的
黄沙基本吹不到这里来，加之这儿是南来客商群集之地，所以地
面打扫得很干净。往北去就是坦皇路，南北两边则是长长的华严
路，南面不远处高大威峨的建筑就是大同府城的南门。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"huayanlu3",
  "east" : __DIR__"huayanlu4",
  "south" : __DIR__"nanmen",
  "north" : __DIR__"tanhuanglu3",
]));

	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}
