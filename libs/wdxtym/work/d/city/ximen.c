// Room: /city/ximen.c
inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "西门");
	set("long", @LONG
这是西城门，几年前曾经遭到土匪的攻打，因此显得有些破败。城门正上
方勉勉强强可以认出“西门”两个大字，城墙上贴着几张通缉告示。
一条笔直的青石板大道向东西两边延伸。西边是郊外，东边是城里。
LONG );
	set("outdoors", "city");
	set("item_desc", ([
		"【告示】" : (: look_gaoshi :),
	]));

	set("exits", ([
		"east"  : __DIR__"xidajie2",
		"west"  : __DIR__"ximenroad",
		"south" : __DIR__"shangjinleitai",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
		"/d/mingjiao/npc/fenggongying" : 1,
	]));
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n扬州知府\n程药发\n";
}

