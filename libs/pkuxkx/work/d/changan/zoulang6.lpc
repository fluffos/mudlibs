
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "走廊");
        set("long", @LONG
这是尚书省的北走廊，北面是礼部，东面通向吏部。
LONG        );
        
        set("exits", ([
                "east" : __DIR__"zoulang2",
                "north" : __DIR__"ss-libu2"
        ]));
        
        set("locate_level",3);
        set("changan", 2); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}