// 大轮寺
//by kiden

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "善禅渡");
        set("long", @LONG
前望一道石阶蜿蜒而上，在峰峦中时隐时现，直没入山腰云端之中。
真是：
    身游万死一生地，路入千峰百障中。
    一径入松雪，数峰生暮寒。
LONG 
        );

        set("exits", ([

                "east" : __DIR__"tianhu",
                "northwest" : __DIR__"qianbuling1",


        ]));
        set("objects", ([
//                __DIR__"npc/randomnpc2" : 1,
        ]));
        set("outdoors", "dalunsi");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

