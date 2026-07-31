// Room: southgate.c
inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "南城门");
	set("long", @LONG
这是成都南城门，城门正上方刻着“南门”两个楷书大字，城墙
上贴着几张官府告示(gaoshi)。一条笔直的青石板大道向南延伸。南
边是郊外，遍地麦浪金黄迷人。北边是城里。
LONG
	);
	set("outdoors", "chengdu");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
		"south"  : __DIR__"nanheqiaos",
		"north"  : __DIR__"southroad2",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing"    : 2,
	]));
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n成都提督\n吴天德\n";
}
