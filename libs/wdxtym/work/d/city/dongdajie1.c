// Room: /city/dongdajie1.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
这是一条宽阔的青石板街道。东边不时地传来金属撞
击声，西边人声嘈杂。北边是一座简朴的院子，大门上方写着“白
鹿书院”四个烫金大字。南边是一家杂货铺。
LONG );
	set("outdoors", "city");
	set("exits", ([
		"east" : __DIR__"dongdajie2",
		"south" : __DIR__"zahuopu",
		"west" : __DIR__"guangchang",
		"north" : __DIR__"shuyuan",
	]));

	set("objects", ([
		"/clone/npc/xunbu" : 1,
		"/d/boss/jiangshi": 3,

	]));
	setup();
}

