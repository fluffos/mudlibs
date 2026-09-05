
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "走廊");
        set("long", @LONG
这是尚书省的南走廊，南面是工部，东面通向兵部。。
LONG        );
        
        set("exits", ([
                "east" : __DIR__"zoulang1",
                "south" : __DIR__"ss-gongbu"
        ]));
        
        set("locate_level",3);
        set("changan", 2); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}