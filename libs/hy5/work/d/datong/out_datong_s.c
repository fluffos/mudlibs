
inherit ROOM;

void create()
{
	set("short", "大同府南门外");
	set("long", @LONG
这里便是大同府的南门外了，高大威严的南门楼耸立在你的
面前，一队官兵迈着整齐的步伐从你身边走过，几名差役正拦住
一名客商盘问着什么。
LONG
	);

	set("exits", ([

  "north" : __DIR__"nanmen",
   "south" : "/d/huanghe/huanghe_3",
]));
	set("objects",([
	"/d/city/npc/bing" : 3,
]));
	set("outdoors","datong");

	setup();


	replace_program(ROOM);
}
