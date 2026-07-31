//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "妃丽湖南岸");
	set("long", @LONG
这里是休猎部的渔船码头。岸边有台夷村民正在扎制竹筏，一些
渔民划着竹筏下湖捕鱼，新鲜的鱼鳖可以在附近的喜州、龙口等城镇
卖出好价钱。
LONG
        );

	set("exits", ([
		"south" : __DIR__"minov72",
		]));

	set("objects", ([
		__DIR__"npc/tyfisher" : 1,
	]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
