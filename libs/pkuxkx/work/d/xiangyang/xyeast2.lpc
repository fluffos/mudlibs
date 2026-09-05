

#include <ansi.h>
inherit ROOM;

void create ()
{
    set("short",HIC"东街"NOR);
set("outdoors","xiangyang");
    set("long",
YEL"这里是襄阳东街,兵荒马乱的年月,这里早失去了往日的繁华.
   北边有一座大院,那就是天下闻名的郭靖大侠的家.
   郭大侠忧国忧民,很少回家,从大门往里望,只有一个中年女佣在打扫.\n"NOR
       );
 
    set("exits", ([/*sizes of 3*/
        "west" :   __DIR__"xyeast1",
        "east" :   __DIR__"xyeast3", 
        "north" :  __DIR__"keting",
        "southwest":   "/d/wuguan/wuguan_damen",
        ])); 
}
int valid_leave(object me,string dir)
{
    if (dir=="southwest"&&!userp(me))
    {
        return 1;
    }
    return ::valid_leave(me,dir);
}