
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "淑景殿");
        set("long", @LONG
淑景殿和周边的宫殿都是嫔妃门居住的宫殿，四周小桥流水，绿树成荫，
繁花似镜，风景优美。
LONG    );
        
        set("exits", ([
                "east" : __DIR__"ganludian",
                "west" : __DIR__"jiayoumen"
        ]));
        
        set("locate_level",2);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}