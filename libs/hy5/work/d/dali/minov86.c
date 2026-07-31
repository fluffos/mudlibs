//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "乌夷民居");
	set("long", @LONG
这是一所乌夷族的房屋。乌夷民居的建地和走向讲究依傍四面山
势，一般以石为墙和基，以木为梁，结构大致和汉人房屋相仿，皆是
平房，石砌围墙。这家院内有一排木架，挂了些山鸡、野鸭、羚羊等
猎物，一个猎人正在给猎物剥皮开膛。
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov84",
		]));

	set("objects", ([
		__DIR__"npc/wylieren.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
