
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "走廊");
        set("long", @LONG
这是尚书省的北走廊，北面是吏部，东面通向户部，西面通向礼部，楼上是
都堂，南面通向兵部、刑部、工部等几个衙门。
LONG        );
        
        set("exits", ([
                "southdown" : __DIR__"shangshusheng",
                "southup" : __DIR__"ss-dutang",
                "east" : __DIR__"zoulang5",
                "west" : __DIR__"zoulang6",
                "north" : __DIR__"ss-libu",
                "south" : __DIR__"zoulang7"
        ]));
        
        set("locate_level",3);
        set("changan", 2); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}