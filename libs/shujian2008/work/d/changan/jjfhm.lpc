// Write By Yanyang@SJ 2001.10.1
// Room: /d/changan/jjfhm.c

inherit ROOM;
#include <room.h>;

void create()
{
        set("short", "后门");
        set("long", @LONG
这里是将军府的后门。再往里走就是后花园了，还没进门，你便闻到一股
淡淡的花香。
LONG
        );
        set("exits", ([
                "north"  : __DIR__"jjfzht",
                "south"  : __DIR__"jjfhhy",
                ]));

        set("incity",1);
	setup();
        create_door("south","铁门","north",DOOR_CLOSED);
}
