// Room: /dali/xijie2.c
// bbb 1997/06/11
// Modify By River 98/12/
inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
你走在西大街上，街道上花草和树木郁郁葱葱，花香阵阵，街面是由碗口
大的彩色石块铺成，青兰紫绿，煞是好看。城内居民族裔繁杂，习俗各异，饮
食穿着无不异于中原。西面是个戏院，正热闹地上演着好戏。
LONG
	);
	set("outdoors", "大理");
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"xiyuan",
		"north" : __DIR__"xijie5",
		"south" : __DIR__"xijie7",
	]));
	set("incity", 1);
	setup();
}
