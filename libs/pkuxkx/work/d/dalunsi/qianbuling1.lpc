// 大轮寺
//by kiden

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "千步岭");
        set("long", @LONG
这里山势平缓，拾阶而上不甚费力，前面山岭据说走一千步就可越过。
真是：
    千里断肠关山古道，回首高城似天杳。
    天涯倦旅，此时心事良苦。
LONG 
        );

        set("exits", ([

                "westup" : __DIR__"qianbuling2",
                "southeast" : __DIR__"shanchandu",


        ]));
        set("objects", ([
//                __DIR__"npc/chou1" : 1,

        ]));
        set("outdoors", "dalunsi");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

