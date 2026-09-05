
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "春明门大街");
        set("long", @LONG
这里是长安的东大街，东面通向春明门，西面通向朱雀大街，
北面就是大唐最高学府国子监。
LONG    );
        
        set("exits", ([
                "west" : __DIR__"zhuque",
                "east" : __DIR__"eaststreet-2",
                "south" : __DIR__"qinyuan",
                "north" : __DIR__"guozijian"
        ]));

        set("outdoors", "changan");
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
   
}


