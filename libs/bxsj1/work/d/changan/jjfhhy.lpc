// Write By Yanyang@SJ 2001.10.1
// Room: /d/changan/jjfhhy.c

inherit ROOM;
#include <room.h>;

void create()
{
        set("short", "后花园");
        set("long", @LONG
一个小花园，虽然比不上富豪大院里的万紫千红，但也布置得精致可人。
将军府里显然不乏高雅之士。春天里桃花盛开，夏日池塘里荷花田田，秋天里
菊花争艳，冬天则是一片香雪海。
LONG
        );
        set("outdoors", "长安");
        set("exits", ([
                "west"   : __DIR__"jjflt",
                "north"  : __DIR__"jjfhm",
        ]));

        set("incity",1);
	setup();
        create_door("north","铁门","south",DOOR_CLOSED);
       
}
