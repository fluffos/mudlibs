
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "春明门大街");
        set("long", @LONG
这里是长安的东大街，东面通向春明门，西面通向朱雀大街，
北面通向丹凤门，南面是热闹的东市。
LONG    );
        
        set("exits", ([
                "west" : __DIR__"eaststreet-1",
                "north" : __DIR__"danfengstreet-2",
                "south" : __DIR__"eastmarket-1",
                "east" : __DIR__"eaststreet-3",               
        ]));

        set("outdoors", "changan");
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
   
}


