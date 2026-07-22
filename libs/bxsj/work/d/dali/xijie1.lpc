// Room: /dali/xijie2.c
// bbb 1997/06/11
// Modify By River 98/12/
inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
这是大理西大街，大理百姓把这里叫三月街，又叫观音街。是白族三月贸
市古街。每到三月，这里挤满了交易的人群。向东走是座酒楼，不时有香气传
过来。还有不少人在西边的裁缝店里挑选衣服。
LONG
	);
	set("outdoors", "大理");
	set("exits", ([ 
		"east" : __DIR__"fengwei",
		"west" : __DIR__"caifeng",
		"north" : __DIR__"beijie1",
		"south" : __DIR__"xijie2",
	]));
	set("objects", ([
		__DIR__"npc/haoke" : 1,
	]));
	set("incity", 1);
	setup();
}
