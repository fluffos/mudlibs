//Create by jason@pkuxkx
//铁掌帮
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "湿地");
        set("long", @LONG
这片湿地相对沼泽已经安全的多了。东边有一座小山。
LONG    );
        set("exits", ([ 
        "west": __DIR__"zhaoze_config/exit",
        "east": __DIR__"xiagu"
]));
        set("no_clean_up", 0);
        set("outdoors", "tiezhang");

        setup();        
}

int valid_leave(object me,string dir)
{    
    if(dir == "east" && JIAOFEI_D->istaskstart() != 1)
    {
        return notify_fail("铁掌帮警戒严密，再往前太危险了。\n");
    }
    return ::valid_leave(me,dir);
}