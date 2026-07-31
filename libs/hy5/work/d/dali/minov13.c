//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "农田");
	set("long", @LONG
这是一小块普通的水田地，南诏温暖潮湿，自古以来就以种植水
稻为主。这附近是大理地区少见的平原地形，主要以耕作为生的摆夷
人开垦了一些的农田。田地划分成小块，一些摆夷男子正在田里引着
水牛耕作。有道路穿过农田向东而去。
LONG
        );

	set("exits", ([
		"west" : __DIR__"minov11",
		"east" : __DIR__"minov16",
		"south" : __DIR__"minov14",
		]));

	set("objects", ([
		__DIR__"npc/niu.c" : 1,
		__DIR__"npc/bynong.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
