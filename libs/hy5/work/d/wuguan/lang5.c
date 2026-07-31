//cool 98.4.18

inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long", @LONG
这是个长廊，通向馆主的卧室，这里静悄悄的，没有什么人来，
走廊两边爬满了爬山虎，外面烈日，可是你走在走廊里只觉得一阵
清凉。
LONG);
	set("exits", ([
               "out" : __DIR__"dating",
               "east" : __DIR__"shufang",
               "north" : __DIR__"woshi",
        ]));
        set("objects", ([
           __DIR__"npc/yahuan" : 1,
        ]));
	setup();
        replace_program(ROOM);
}

