//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "竹楼下");
	set("long", @LONG
台夷人喜居竹林深处，房舍自然少不了用竹子搭成，竹为梁，竹
为墙，竹楼建的相当精致。下层基本上只是四根柱子架空的，既可以
作兽圈，也为了防蛇。一架竹梯通向上层的房舍。
LONG
        );

	set("exits", ([
		"up" : __DIR__"minov69",
		"south" : __DIR__"minov67",
		]));

	set("objects", ([
		__DIR__"npc/niu" : 1,
	]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
