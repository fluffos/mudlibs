// Room: /d/fouzhou/huadian.c
// lklv 2001.9.8

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","花店");
        set("long", @LONG
这是福州城西大大有名的一家花店，店里摆放着各种各样的鲜花，空气里
弥散着醉人的花香。人一走进来，就会不由自主的陶醉了。这里的鲜花品种很
全，来自全国各地的都有。美丽的卖花姑娘手拿剪子正在修剪花枝。
LONG
        );
        set("exits", ([
                "east" : __DIR__"xixiang3",
        ]));
        set("objects", ([
                NPC_D("flowergirl") : 1,
        ]));
	setup();
}
