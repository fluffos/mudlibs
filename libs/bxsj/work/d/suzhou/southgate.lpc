// Room: /city/nanmen.c

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "南门");
	set("long", @LONG
这是南城门，城墙被当成了广告牌，贴满了花花绿绿各行各业的广告，
官府的告示(gaoshi)因此不太显目。官兵们被近处的欢声笑语所吸引，似乎
不是很认真在执勤。一条笔直的青石板大道向南北两边延伸。
LONG
	);
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("outdoors", "苏州");
	set("exits",([
		"north" : __DIR__"nandajie2",
		"south" : __DIR__"qsgdao2",
	]));
	set("objects", ([
		NPC_D("guanfu/wujiang") : 1,
		NPC_D("guanfu/bing") : 2,
	]));
	set("incity",1);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n苏州知府\n赵知仁\n";
}
