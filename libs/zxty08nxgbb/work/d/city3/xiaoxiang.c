// Room: /chengdu/xiaoxiang.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "小巷");
	set("long", @LONG
这里是一条幽深的小巷，不知道通向那里。这里不时地有
本地居民走过，你也许可以向他们打打听听。
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "south" : __DIR__"xijie",
                "north" : __DIR__"xiaoxiang1",
	]));

	setup();
	replace_program(ROOM);
}

