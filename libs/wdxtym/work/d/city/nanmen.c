// Room: /city/nanmen.c
inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "南门");
	set("long", @LONG
这是南城门，城墙被当成了广告牌，贴满了花花绿绿各行各业的广告，
官府的告示因此不太显目。官兵们被近处的欢声笑语所吸引，似
乎不是很认真在执勤。一条笔直的青石板大道向南北两边延伸。
LONG );
	set("outdoors", "city");
	set("item_desc", ([
		"【告示】" : (: look_gaoshi :),
	]));

	set("exits", ([
		"south" : "/d/wudang/wdroad1",
		"north" : __DIR__"nandajie2",
		"west"  : __DIR__"jiaowai8",
		"east"  : __DIR__"jiaowai7",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
		__DIR__"npc/shisong" : 4,
	]));
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n扬州知府\n程药发\n";
}

