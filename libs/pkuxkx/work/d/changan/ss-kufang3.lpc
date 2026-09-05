
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "杂物库房");
        set("long", @LONG
这是尚书省户部衙门所属的杂物库房，主要存放各地收集来的用途不明的物品。
LONG        );
        
        set("exits", ([
                "west"    : __DIR__"ss-kufang",
        ]));
        
        set("objects", ([
          __DIR__"npc/kf-manager": 1,
        ]));
        
        set("type", "item");
        set("locate_level",3);
        set("changan", 2); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}