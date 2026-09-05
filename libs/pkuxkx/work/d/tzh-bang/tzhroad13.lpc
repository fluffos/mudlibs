// Room: tzhroad13-小食店
// to wolf

inherit ROOM;

void create()
{
	set("short", "小食店");
	set("long", @LONG
    这里是村庄里面唯一的一间小食店，因为是唯一一间的关系，生意特别好。台子
差不多都坐满了。而顾客都是以村庄和铁掌帮的人居多。
LONG
	);

	set("exits", ([
		"north" : __DIR__"tzhroad9",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));

	setup();
	replace_program(ROOM);
}

