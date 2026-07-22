// Room: /d/xingxiu/xx6.c
// Modify by Lklv 2001.10.16

inherit ROOM;

void create()
{
	set("short", "海边荒路");
	set("long", @LONG
一条崎岖的小路，东面是方圆几百里，一望无际的星宿海，靠西是一片山
石。这里荒无人烟，寒风凛冽。枯树败草间，不时有毒虫出没。你感到有点乏
力，歇了一口气再往前走。
LONG);
	set("outdoors", "星宿");
	set("exits", ([
		"east" : __DIR__"xxh2",
		"south" : __DIR__"xxh4",
		"north" : __DIR__"xxh3",
		"westup" : __DIR__"shanshi",
        ]));
	set("objects", ([
                __DIR__"npc/boshou"  : 1,
                __DIR__"npc/xxdizi" : 1,
        ]));
        setup();
}

