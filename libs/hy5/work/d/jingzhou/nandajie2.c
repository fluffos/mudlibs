// Room:nandajie2.c
// congw 98/08/29
inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
你走在一条繁华的街道上，向南北两头延伸。南边是南城门，北边通往市中心，西
边是一家顾客众多荆州的兵器库，东边是荆州粮仓，荆州向来是军事要地，所以兵
器粮草屯积丰厚。
LONG
	);
        set("outdoors", "jingzhou");

	set("exits", ([
                "east" : __DIR__"lcmen",
                "south" : __DIR__"jznanmen",
                "west" : __DIR__"bqkumen",
		"north" : __DIR__"nandajie1",
		"westdown" : __DIR__"lydao4",
	]));
        	setup();
}


