
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "函谷琴苑");
        set("long", @LONG
这是函谷八友的老大琴颠康广陵开办的乐器店，专门
售卖各类乐器曲谱。
LONG
        );

        set("exits", ([
               "north" : __DIR__"eaststreet-1",
        ]));
        set("objects", ([
                __DIR__"npc/kang-guangling":1
        ]));
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
        
}