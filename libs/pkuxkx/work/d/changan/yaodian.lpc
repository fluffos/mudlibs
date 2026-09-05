
#include <ansi.h>
#include <localtime.h>
inherit ROOM;
void create()
{
        set("short", HIC"千金堂"NOR);
        set("long", @LONG
这是名医孙思邈开的药铺，由于药王不时过来坐诊，千金堂在
长安城附近声名显赫，远近闻名。
LONG
        );

        set("exits", ([
               "east" : __DIR__"westmarket-3",
        ]));
        set("objects", ([
                __DIR__"npc/sunsimiao":1,   
                __DIR__"npc/yphuoji":1             
        ]));
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
        
}