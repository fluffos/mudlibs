
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "右羽林军营");
        set("long", @LONG
这是驻扎在玄武门北面的右羽林军大营，羽林军乃是皇帝禁军，
专门负责禁宫安全，保卫长安的北大门。
LONG        );
        
        set("exits", ([
                "east" : __DIR__"xuanwumen"
        ]));
        
        set("outdoors", "changan");
        set("changan", 0); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}