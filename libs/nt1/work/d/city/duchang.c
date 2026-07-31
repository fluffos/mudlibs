// Room: /city/duchang.c
// YZC 1995/12/04 

inherit AREA_ROOM;

void create()
{
	set("short", "赌场");
	set("long", @LONG
这里是赌场的大堂，四周的房间里传出来吆五喝六的赌博声。西边是
赌「大小」的房间。墙上显眼处挂着一块牌子(paizi)。
LONG );
	set("item_desc", ([
		"paizi" : "二楼的拱猪房正处于测试阶段。\n",
	]));
	set("objects", ([
		CLASS_D("shenlong")+"/pang" : 1,
                __DIR__"npc/boss" : 1,
	]));
        set("area/ziyuan", "货币");
	set("exits", ([
		"west" : __DIR__"daxiao",
//                "north" : "/u/sinb/shaizifang",
		"up"   : __DIR__"duchang2",
		"east" : __DIR__"nandajie1",
	]));
	setup();
}

