// /d/wudang/zxgdamen.c  紫霄宫大门
// by ydh
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",MAG"紫霄宫大门"NOR);
        set("long", @LONG
你已到了展旗峰下，前面就是武当山最为宏大的宫宇紫霄宫了。殿宇依山
而筑，高低错落有致。周围古木参天，翠竹成林，鸟语花香，景色清幽，好一
个修道成仙处。这里是武当师徒的主要活动场所。
LONG
        );
        set("exits", ([
                "enter" : __DIR__"zixia",
                "northdown" :__DIR__"shijie3",
        ]));

        set("objects",([
                CLASS_D("wudang")+ "/fengsong" : 1,
                __DIR__"npc/daotong" :2,
        ]));
        
        set("outdoors","武当");
        setup();
}
