
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "装备库房");
        set("long", @LONG
这是尚书省户部衙门所属的装备库房，主要存放普通士兵使用的武器护甲等。
LONG        );
        
        set("exits", ([
                "east"    : __DIR__"ss-kufang",
        ]));
        
        set("objects", ([
          __DIR__"npc/kf-manager": 1,
        ]));
        
        set("type", "equip");        
        set("locate_level",3);
        set("changan", 2); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}