
#include <ansi.h>
inherit ROOM;

void create ()
{
    set("short",HIC"东街"NOR);
  set("outdoors","xiangyang");
    set("long",
YEL"这里是襄阳东街, 兵荒马乱的年月,这里早失去了往日的繁华.
街上有一股浓浓的中药味,北手一家买卖,挂着金字招牌,原来是个药铺.\n"NOR
       );
 
    set("exits", ([/*sizes of 3*/
        "west" :   __DIR__"xycenter",
        "east" :   __DIR__"xyeast2", 
        "north":   __DIR__"yaopu",
        "southeast":   "/d/wuguan/wuguan_damen",
           ])); 
set("objects",([
"/d/pker/npc/guomo":1,

]));
setup();

}

int valid_leave(object me,string dir)
{
    if (dir=="southeast"&&!userp(me))
    {
        return 1;
    }
    return ::valid_leave(me,dir);
}