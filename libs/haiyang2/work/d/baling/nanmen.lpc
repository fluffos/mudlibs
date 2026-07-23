// baling/nanmen
// Room in 龟兹 
// laowuwu 99/04/11
// Modify by yang

inherit ROOM;

void create()
{
	set("short", "南门");
	set("long", @LONG
这是南城门，城墙被当成了广告牌，贴满了花花绿绿各行各业的广
告，官府的告示因此就不太显目。官兵们被近处的欢声笑语所吸引，似
乎不是很认真在执勤。一条笔直的青石板大道向南北两边延伸。
LONG
	);
        set("outdoors", "baling");

	set("exits", ([
		"south" : __DIR__"edao6",
		"northeast" : __DIR__"nandajie3",
	]));
     set("objects", ([
		__DIR__"npc/bing" : 2,
                __DIR__"npc/wujiang" : 1
	]));
	setup();
	replace_program(ROOM);
}

