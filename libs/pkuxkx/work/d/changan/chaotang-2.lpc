
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "西朝堂");
        set("long", @LONG
这是含元殿西南角的一个朝堂，是每月朔望两日大朝百官
觐见的时候休息场所。
LONG        );
        
        set("exits", ([
                "northeast" : __DIR__"hanyuandian",
                "southeast" : __DIR__"dfguangchang"
        ]));
        
        set("locate_level",3);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙        
        setup();
}