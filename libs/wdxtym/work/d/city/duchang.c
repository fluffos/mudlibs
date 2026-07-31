// Room: /city/duchang.c
inherit ROOM;
void create()
{
	set("short", "赌场");
	set("long", @LONG
这里是赌场的大堂，四周的房间里传出来吆五喝六的赌博声。
西边是赌「大小」的房间。墙上显眼处挂着一块牌子。
LONG );
	set("item_desc", ([
		"【牌子】" : "二楼的拱猪房正处于测试阶段。\n",
	]));
	set("objects", ([
		CLASS_D("shenlong")+"/pang" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"daxiao",
		"up"   : __DIR__"duchang2",
		"east" : __DIR__"nandajie1",
	]));
	setup();
}

