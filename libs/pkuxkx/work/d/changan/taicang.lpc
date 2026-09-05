
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "太仓");
        set("long", @LONG
太仓是长安城储备粮食的仓库，周围守卫森严，严禁烟火。
东面从嘉猷门可以通向内廷。
LONG    );
        
        set("exits", ([
           "east" : __DIR__"jiayoumen",
           "south" : __DIR__"yetinggong"
        ]));
        
        set("locate_level",2);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}