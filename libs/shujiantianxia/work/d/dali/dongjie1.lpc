// Room: 大理东大街 /dali/dongjie1
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
这是大理东大街，街道上花草和树木郁郁葱葱，花香阵阵。西面不时传来
阵阵诱人的香味，原来是有名的云雪楼。东面是个当铺，很多穷苦人家为了生
计不得不把家中值钱的东西典当换钱。往北走就是大理的北大街了。
LONG
	);
	set("outdoors", "大理");
	set("exits", ([ 
		"east" : __DIR__"dangpu",
		"west" : __DIR__"jiulou",
		"north" : __DIR__"beijie5",
		"south" : __DIR__"dongjie2",
	]));
	set("incity", 1);

	setup();
}
