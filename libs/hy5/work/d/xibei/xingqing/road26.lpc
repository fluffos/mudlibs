//road26.c.景平坊
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"景平坊"NOR);
    set("long",@LONG
这里是景平坊。周围大多是平民住宅，及一些店铺. 驿道上负责治安的马鹞
军加紧对来往客商的盘查，以防有细作混入，千万别招惹他们。这里的居民出奇
的少，这里来回出入的人都显得很神秘，平时一般的百姓都不到这儿来。
LONG);
   
    set("exits",([
///            "north"     : "/d/zuzhi/yipin_tang/xiaodao1", 
             "south"   : __DIR__"road25",
    ])); 
    
    set("outdoors","xingqing");
    setup();
}
int valid_leave( object who, string dir )
{
    if ( !userp( who ) && dir == "north" )
        return 0;
    return ::valid_leave( who, dir );
}

