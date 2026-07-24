// Room: /d/tangmen/xiaoxiao-lou.c
// xws 1998/11/05

inherit ROOM;

void create()
{
	set("short", "潇潇暮雨楼");
	set("long", @LONG
	潇潇暮雨楼虽然称作楼，但是却只有一层。这可能是唐门内最具特色的建筑
楼中有螺旋状悬梯延四周盘旋而上，足足有十几丈高，登上最高处，甚至可以看见远
处烟雨朦胧的长江江面。正是“潇潇暮雨洒江天”的美景。
LONG
	);
	

	set("exits", ([
		"north" : __DIR__"changlang20",
		"west" : __DIR__"bingqiku",
		"eastup" : __DIR__"jiaolou4",
		"south" : __DIR__"changlang12",
	]));

	setup();
	replace_program(ROOM);
}

