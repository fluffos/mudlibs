//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "镇雄");
	set("long", @LONG
这里是乌撒部的聚居中心，乌撒是乌蛮族的大部，属乌夷，领有
巴的甸、镇雄、和附近的威宁。这是一座石砌小城，人口不多，居民
散居在镇子附近，镇子上主要是一些商铺和祭祀所。
LONG
        );

	set("exits", ([
		"south" : __DIR__"minov41",
		"west" : __DIR__"minov43",
		"north" : __DIR__"minov47",
		"northeast" : __DIR__"minov48",
		"east" : __DIR__"minov51",
		]));

	set("objects", ([
		__DIR__"npc/wymuyang.c" : 1,
		__DIR__"npc/wyshang.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
