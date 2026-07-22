// Room: /chengdu/mj.c
// oooc: 1998/06/24 

inherit ROOM;

void create()
{
        set("short", "民居");
	set("long", @LONG
这里是民居，有几个居民在烧火做饭。
LONG
	);

	set("exits", ([
                "west" : __DIR__"nanjie1",
	]));

        set("objects", ([
             __DIR__"npc/poorman" : 1,
        ]));

	setup();
}

