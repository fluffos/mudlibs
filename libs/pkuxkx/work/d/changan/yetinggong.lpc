
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "掖庭宫");
        set("long", @LONG
掖庭宫是宫女和罪臣家属妇女配没入宫的居所，北面是京城的粮仓太仓，
南面是宦官管理机构内侍省。
LONG    );
        
        set("exits", ([
           "east" : __DIR__"tongmingmen",
           "northeast" : __DIR__"jiayoumen",
           "north" : __DIR__"taicang",
           "southwest" : __DIR__"neishisheng"
        ]));
        
        set("locate_level",2);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙        
        setup();   
}