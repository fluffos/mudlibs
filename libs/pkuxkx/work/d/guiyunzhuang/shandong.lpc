// shandong.c 黑风山洞
// Made By:pingpang
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIC"黑风山洞"NOR);
        set("long", @LONG
这里是一个山洞，到处都是白色的骷髅，北面雾气腾腾看不太清楚，似乎有两个人影。
LONG
        );
        set("exits", ([ 
"north" : __DIR__"shandong1",
            "south" : __DIR__"shanlu3",
        ]));
        set("objects", ([ 
        CLASS_D("taohua") + "/mei":1,
        __DIR__"obj/kulou":3,
        __DIR__"obj/baigu":2,
        ]) );

        set("no_clean_up", 0);
        set("outdoors", "guiyunzhuang");

        setup();
        replace_program(ROOM);
}

