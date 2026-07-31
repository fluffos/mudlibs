// Room: /chengdu/nanjie1.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "南大街");
	set("long", @LONG
这条街上，双人合抱的大树在街边十步一株，整整齐齐，青
石铺就的街面打扫得干干净净。你没事最好不要在这里溜达，因
为这里是成都的王府大街。西边一座牌楼，金碧辉煌，令人目为
之眩，这便是梁王府。东边则是一些民居。
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "south" : __DIR__"nanjie",
                "north" : __DIR__"guangchang",
                "west" : __DIR__"wang",
                "east" : __DIR__"mj",
	]));

	setup();
	replace_program(ROOM);
}

