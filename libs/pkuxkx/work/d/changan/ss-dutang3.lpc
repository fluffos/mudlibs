
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "都堂");
        set("long", @LONG
这是尚书右仆射的办公场所，东面是左仆射的办公场所。
LONG        );
        
        set("exits", ([
                "east" : __DIR__"ss-dutang"
        ]));

        set("objects", ([
          __DIR__"npc/puye-2": 1,
        ]));
        
        set("locate_level",3);
        set("changan", 2); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}