
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "金光门大街");
        set("long", @LONG
这里是长安的西大街，西面通向金光门，南面是热闹的西市。
LONG    );
        
        set("exits", ([
                "north" : __DIR__"shantang",
                "west" : __DIR__"weststreet-3",
                "south" : __DIR__"westmarket-1",
                "east" : __DIR__"weststreet-1",
                
        ]));

        set("outdoors", "changan");
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}


