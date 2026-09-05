
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "金光门大街");
        set("long", @LONG
这里是长安的西大街，西面通向金光门，北面沿着皇城角
通向通化门大街，东面通向朱雀大街。
LONG    );
        
        set("exits", ([
                "north" : __DIR__"sanmenstreet-1",
                "west" : __DIR__"weststreet-2",
                "east" : __DIR__"zhuque", 
                "south" : __DIR__"zhifu"               
        ]));

        set("outdoors", "changan");
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}


