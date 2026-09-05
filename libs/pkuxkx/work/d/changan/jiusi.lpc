
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "酒肆");
        set("long", @LONG
这是波斯人开办的一家胡姬酒肆，里面时常有波斯来
的女子过来跳舞助兴。
LONG        );
        
        set("exits", ([
                "west" : __DIR__"westmarket-2"
        ]));

        set("objects", ([
                "/d/changan/npc/huji":1
        ]));
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙        
        setup();   
}