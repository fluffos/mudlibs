// /u/beyond/hz/qsddao2.c 青石大道

inherit ROOM;
void create()
{
        set("short","青石大道");
        set("long", @LONG
你走在一条林荫大道上，两边鸟语花香，游客们往来穿梭，熙熙攘攘好
不热闹。你也兴致勃勃地继续在杭州观赏美丽的风景。大道西面是通往玉泉。
西北是令人仰慕的岳王庙，东南是一条大道。
LONG
        );
	set("objects",([
		__DIR__"npc/you1" : 2,
	]));
	set("exits", ([
		"south" : __DIR__"sudi",
		"northwest" : __DIR__"yuemiao",
		"southeast" : __DIR__"qsddao3",
		"west" : __DIR__"yuquan",
	]));
	set("outdoors", "杭州");
	setup();
}
