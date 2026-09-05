
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "户部衙门");
        set("long", @LONG
这是尚书省的户部衙门，户部尚书刘晏办公的场所。
LONG        );
        
        set("exits", ([
                "south" : __DIR__"zoulang5",
                "northdown" : __DIR__"ss-kufang"
        ]));
        
        set("objects", ([
          __DIR__"npc/liu-yan": 1,
        ]));
        
        set("locate_level",3);
        set("changan", 2); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}