// Room: /d/diaoyudao/caodi1.c 草地
// hongdou 98.09.20

inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
这里是军营附近的草地，郁郁葱葱的小草随风摆动，仿佛
海水般荡漾。一阵哗哗的水声从东边传来，你里可能有一条小
溪。东北不远有一片小树林，不知那里有什么？ 
LONG
	);
	
	set("exits", ([
                 "east" : __DIR__"xiaoxi",
		 "northeast" : __DIR__"guolin",
		 "southwest" : __DIR__"caodi2",
	]));

	set("outdoors", "diaoyudao");
	setup();
	replace_program(ROOM);
}

