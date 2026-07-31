// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","青石大道");
	set("long", @LONG
	一条很气派的青石大道,东边是一个练武场。
LONG
	);

	set("exits", ([
		"north" :__DIR__"dingfeng7",
                "south" :__DIR__"dingfeng5",
		 "east" :__DIR__"wgm3",
	]));
	set("objects",([
                __DIR__"npc/jiao_zhong" : 2,
        ]));


	set("outdoors", "heimuya");
	setup();
	replace_program(ROOM);
}

