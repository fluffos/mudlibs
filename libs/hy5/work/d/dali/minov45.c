//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "阿头部");
	set("long", @LONG
阿头部是乌杂蛮的部落，和附近的乌蛮一样，也属于乌夷。这里
山高林密，不熟的人轻率进山，很容易迷路丧命。深山对乌夷猎人来
说却是聚宝盆，山中野物皆是美味。
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov57",
		"westup" : __DIR__"minov53",
		"southeast" : __DIR__"minov46",
		]));

	set("objects", ([
		__DIR__"npc/wylieren.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
