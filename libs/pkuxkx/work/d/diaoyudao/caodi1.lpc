// Room: /d/diaoyudao/caodi1.c 草地
// hongdou 98.09.20

inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
这里是营地南边的草地，草间夹杂着许多小小的野花，海风拂过
散发出阵阵幽香。你踏着软软的小草上，和徇的阳光照在你的身上，
暖洋洋的，仿佛置身于世外桃源。再往南就是钓鱼岛南沙滩。 
LONG
	);
	
	set("exits", ([
        "southwest" : __DIR__"shatan3",
         "north" : __DIR__"junying1",
		 "east" : __DIR__"caodi2",
	]));

	set("outdoors", "diaoyudao");
	setup();
	replace_program(ROOM);
}

