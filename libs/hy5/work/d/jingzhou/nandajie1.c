// Room: nandajie1.c
// congw 1998/08/29 

inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
南大街乃是城里的繁华地段，北边是一个热闹的广场。东边是一家打铁铺. 西边是
荆州的驿馆，过往的路人多半都在这里歇脚。
LONG
	);
        set("outdoors", "jingzhou");

	set("exits", ([
                "east" : __DIR__"datiepu",
		"south" : __DIR__"nandajie2",
                "west" : __DIR__"chaliao",
		"north" : __DIR__"guangchang",
	]));

	setup();
	replace_program(ROOM);
}

