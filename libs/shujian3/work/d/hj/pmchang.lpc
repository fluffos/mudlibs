// pmchang.c 跑马场

inherit ROOM;

void create()
{
        set("short", "跑马场");
        set("long", @LONG
这一大遍草地就是哈萨克族人的跑马场了。广阔的空间和来往的众多商人
使它成为这一带最繁忙的集会地和市场。一年一度的摔跤比赛和跑马节也在这
里举行。
LONG
        );
        set("objects", ([
		__DIR__"npc/hasake" : 1,
		__DIR__"npc/niu" : 1,
		__DIR__"npc/yang" : 1,
		__DIR__"npc/chen" : 1,
        ]));

        set("exits", ([
		"north" : __DIR__"shop",
		"west" : "/d/group/entry/hjroad",
		"southup" : __DIR__"caochang",
		"east" : __DIR__"caoyuan2",
		"southwest" : __DIR__"shuijing",
	]));

	set("outdoors", "草原");
        
	setup();
}
