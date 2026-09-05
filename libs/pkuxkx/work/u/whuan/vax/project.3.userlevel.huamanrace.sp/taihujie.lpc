//taihujie.c 太湖街
//Made by:pingpang
inherit ROOM;

void create()
{
	set("short", "太湖街");
	set("long", @LONG
你从草地中走了出来，来到太湖街上，踩着坚实的青石板地面。
街上人来人往，各地游客为了去[太湖]纷至沓来。这里有一个屠夫在卖肉。
LONG
	);
        set("outdoors", "guiyunzhuang");

	set("exits", ([
		"east":__DIR__"taihujie1",
		"west":__DIR__"caodi4",
		]));
	set("objects",([__DIR__"npc/tufu":1,
	__DIR__"npc/xiaotou":1,
	__DIR__"npc/panguan":1,]));
	setup();
	replace_program(ROOM);
}

