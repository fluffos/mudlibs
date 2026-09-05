inherit ROOM;

void create()
{
	set("short", "太湖街");
	set("long", @LONG
你正走在太湖街上，踩着坚实的青石板地面。街上人来人往，
各地游客为了去太湖游玩，从各地纷至沓来。这里有两个卖艺人。
LONG
	);
        set("outdoors", "guiyunzhuang");

	set("exits", ([
		"west" : __DIR__"taihujie",
		"east" : __DIR__"taihujie2",
		]));
	set("objects",([__DIR__"npc/maiyi":1,__DIR__"npc/maiyi1":1,]));
	setup();
}

void init()
{
}
