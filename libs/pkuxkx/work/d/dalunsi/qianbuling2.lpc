// 大轮寺
//by kiden

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "千步岭");
        set("long", @LONG
脚下山势逐渐陡峭，石阶也窄了许多，道路两旁都是黑压压的树林。
真是：
    万壑有声含晚籁，数峰无语立斜阳。
    已恨碧山相阻隔，碧山还被碧云遮。
LONG 
        );

        set("exits", ([

                "eastdown" : __DIR__"qianbuling1",
                "westdown" : __DIR__"ruyoukou",


        ]));
        set("objects", ([
//                __DIR__"npc/chou1" : 1,

        ]));
        set("outdoors", "dalunsi");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

