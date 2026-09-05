
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "吏部衙门");
        set("long", @LONG
这是尚书省的吏部衙门，吏部尚书李林甫办公的场所。
LONG        );
        
        set("exits", ([
                "south" : __DIR__"zoulang2"
        ]));
        
        set("objects", ([
          __DIR__"npc/li-linfu": 1,
        ]));
        
        set("locate_level",3);
        set("changan", 2); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}