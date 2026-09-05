// shandong1.c 黑风山洞
// Made By:pingpang
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIC"黑风山洞"NOR);
        set("long", @LONG
这里是一个山洞的深处，里面到处是骨架。这里雾气腾腾看不太清楚，似乎有个人影。
LONG
        );
        set("exits", ([ 
            "south" : __DIR__"shandong",
        ]));
        set("objects", ([ 
        CLASS_D("taohua") + "/chen-xuanfeng":1,
        __DIR__"obj/gujia":4,
        __DIR__"obj/baigu":1,
        ]) );

        set("no_clean_up", 0);
        set("outdoors", "guiyunzhuang");

        setup();
        replace_program(ROOM);
}

