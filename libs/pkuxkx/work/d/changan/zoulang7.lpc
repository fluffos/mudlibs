
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "走廊");
        set("long", @LONG
这是尚书省的南北向通道，北面通往吏部、户部、礼部等衙门，
南面通向兵部、刑部、工部等衙门。
LONG        );
        
        set("exits", ([
                "south" : __DIR__"zoulang1",
                "north" : __DIR__"zoulang2"
        ]));
        
        set("locate_level",3);
        set("changan", 2); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}