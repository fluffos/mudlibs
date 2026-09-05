
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "金光门大街");
        set("long", @LONG
这里是长安的西大街，西面通向金光门，东面通向朱雀大街。南边是
西北大名鼎鼎的飞马镖局。
LONG    );
        
        set("exits", ([
                "east" : __DIR__"weststreet-2",
                "west" : __DIR__"westgate",
                "south" : __DIR__"biaoju",
				"north" : __DIR__"machehang",
        ]));

        set("outdoors", "changan");
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}


