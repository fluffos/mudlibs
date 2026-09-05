
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "邢部衙门");
        set("long", @LONG
这是尚书省的邢部衙门，邢部尚书颜真卿办公的场所。
LONG        );
        
        set("exits", ([
                "north" : __DIR__"zoulang3"
        ]));

        set("objects", ([
          __DIR__"npc/yan-zhenqing": 1,
        ]));
        
        set("locate_level",3);
        set("changan", 2); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}