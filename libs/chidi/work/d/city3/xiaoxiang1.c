// Room: /chengdu/xiaoxiang1.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "小巷");
	set("long", @LONG
这里是一条幽深的小巷，不知道通向哪里。这里不时有本
地的居民路过，你可以向他们打听一下。
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "south" : __DIR__"xiaoxiang",
                "northeast" : __DIR__"caotang",
	]));
        set("objects", ([
            __DIR__"npc/shusheng" : 2,
        ]));

	setup();
	replace_program(ROOM);
}

