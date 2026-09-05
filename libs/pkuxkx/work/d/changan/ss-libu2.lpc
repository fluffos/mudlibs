
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "礼部衙门");
        set("long", @LONG
这是尚书省的礼部衙门，礼部尚书许敬宗办公的场所。
LONG        );
        
        set("exits", ([
                "south" : __DIR__"zoulang6"
        ]));
        
        set("objects", ([
          __DIR__"npc/xu-jingzong": 1,
        ]));
        
        set("locate_level",3);
        set("changan", 2); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}