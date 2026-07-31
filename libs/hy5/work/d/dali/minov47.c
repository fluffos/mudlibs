//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "葛鲁城");
	set("long", @LONG
此城是乌蛮族屈部的治府，屈部领葛鲁、昌州、德昌，面积颇大。
附近多山地丛林，居民多狩猎为生，河谷内低地也多草皮，适合放牧
牛羊。此去北和西皆入深山，东边平原上另有村镇。
LONG
        );

	set("exits", ([
		"south" : __DIR__"minov42",
		"northup" : __DIR__"minov52",
		"east" : __DIR__"minov48",
		]));

	set("objects", ([
		__DIR__"npc/wymuyren.c" : 1,
		__DIR__"npc/goat.c" : 2,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
