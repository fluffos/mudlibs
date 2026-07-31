// Room: /dali/dalics.c
// bbb 1997/06/11
// update by cool
// Modify By River 98/12/
inherit ROOM;

void create()
{
	set("short", "城中心");
	set("long", @LONG
这里是大理中心广场，是大理最繁华的所在。白天这里人声鼎沸，晚上更
是灯火通明，忙碌了一天的人们晚上总喜欢到这里走一走，广场上卖各种东西
的都有，不少江湖人物混迹其中。
LONG
	);
	set("outdoors", "大理");
	set("exits", ([ 
		"south" : __DIR__"qsjie1",
		"north" : __DIR__"beijie3",
		"east" : __DIR__"jiulou",
		"west" : __DIR__"fengwei",
	]));
	set("objects", ([
		__DIR__"npc/liumang" : 1,
		__DIR__"npc/guo" : 1, 
	]));
	setup();
}
