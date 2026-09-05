//taihujie2.c 太湖街
//Made by:pingpang
inherit ROOM;

void create()
{
	set("short", "太湖街");
	set("long", @LONG
你正走在太湖街上，踩着坚实的青石板地面。街上人来人往，
各地游客为了去太湖游玩，从各地纷至沓来。这里有一位商人正在卖东西。
LONG
	);
        set("outdoors", "guiyunzhuang");

	set("exits", ([
		"west":__DIR__"taihujie1",
		"east":__DIR__"taihujie3",
		]));
	set("objects",([__DIR__"npc/shangren":1,]));
	setup();
	replace_program(ROOM);
}

