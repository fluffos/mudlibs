
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "走廊");
        set("long", @LONG
这是尚书省的南走廊，南面是兵部，东面通向刑部，西面通向工部，楼上是
都堂，北面通向吏部、户部、礼部等几个衙门。
LONG        );
        
        set("exits", ([
                "northdown" : __DIR__"shangshusheng",
                "northup" : __DIR__"ss-dutang",
                "east" : __DIR__"zoulang3",
                "west" : __DIR__"zoulang4",
                "south" : __DIR__"ss-bingbu",
                "north" : __DIR__"zoulang7"
        ]));
        
        set("locate_level",3);
        set("changan", 2); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}