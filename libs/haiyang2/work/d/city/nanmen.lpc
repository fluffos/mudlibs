// Room: /city/nanmen.c
// YZC 1995/12/04 

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "安定门");
	set("long", @LONG
一座高大的城门耸峙在渡江桥头，城门嵌有「安定门」三字石额。
城墙上建有一个城楼，几个巡逻的官兵们被近处的欢声笑语所吸引，似
乎不是很认真在执勤。左右各有一个水门，便于官河和小秦淮河流通，
及城内外的水运的便利。城墙被当成了广告牌，贴满了花花绿绿各行各
业的广告，城门口贴着几张榜文告示(gaoshi)因此不太显目。大量的行
人车辆进出安定门，熙熙攘攘的人群立即使人感受到扬州的繁华。
LONG );
        set("outdoors", "city");
//	set("no_clean_up", 0);
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
		"south" : "/d/wudang/wdroad1",
		"north" : __DIR__"nanmendajie",
		"west"  : __DIR__"jiaowai8",
		"east"  : __DIR__"jiaowai7",
	]));
        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
		"/d/city2/npc/shisong" :1,
        ]));
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n扬州知府\n程药发\n";
}

