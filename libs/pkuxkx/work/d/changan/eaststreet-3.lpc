
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "春明门大街");
        set("long", @LONG
这里是长安的东大街，东面通向春明门，西面通向朱雀大街，
北面是南大内兴庆宫。
LONG    );
        
        set("exits", ([
                "west" : __DIR__"eaststreet-2",
                "east" : __DIR__"eastgate",
                "north" : __DIR__"tongyangmen"
        ]));

        set("outdoors", "changan");
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
   
}


