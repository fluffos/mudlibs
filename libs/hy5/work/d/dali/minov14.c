//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "杆栏");
	set("long", @LONG
摆夷族大多依树积木以居其上，就是杆栏，在夷语里叫做榔盘。
其构造大致略似楼，侧面开门，有梯可上下，上阁如车盖状，中层住
人，这里是下层，一般为牛羊圈。
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov13",
		"up" : __DIR__"minov15",
		]));

	set("objects", ([
		__DIR__"npc/goat.c" : 2,
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
