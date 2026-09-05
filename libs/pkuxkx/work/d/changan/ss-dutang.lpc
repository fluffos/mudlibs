
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "都堂");
        set("long", @LONG
这是尚书省长官的办公场所，楼下是六部衙门的办公场所，东面通向
左仆射办公场所，西面通向右仆射办公场所。
LONG        );
        
        set("exits", ([
                "southdown" : __DIR__"zoulang1",
                "northdown" : __DIR__"zoulang2",
                "east" : __DIR__"ss-dutang2",
                "west" : __DIR__"ss-dutang3"
        ]));
        
        set("locate_level",3);
        set("changan", 2); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}