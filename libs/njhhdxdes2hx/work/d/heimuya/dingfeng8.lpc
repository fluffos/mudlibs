// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","青石大道");
	set("long", @LONG
	一条很气派的青石大道,约有五丈来宽，是用一色的大青石砌成，由于人们
经常走动的缘故，一点青苔也没有，光光的露出石头的原色。
LONG
	);

	set("exits", ([
		"north" :__DIR__"dingfeng9",
                "south" :__DIR__"dingfeng7",
	]));
	set("objects",([
                __DIR__"npc/jiao_zhong6" : 4,
        ]));


	set("outdoors", "heimuya");
	setup();
	replace_program(ROOM);
}

