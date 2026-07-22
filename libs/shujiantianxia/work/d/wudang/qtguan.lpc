// /area/jiangbei/wudang/qtguan.c 琼台观
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"琼台观"NOR);
        set("long", @LONG
琼台观位于武当山天柱峰东南八公里处，分为琼台上观、中观和下观三个
建筑单元，是武当山三十六观中最大的道观之一。琼台三观各有非常好听的名
字，上观叫“白玉龟台”，中观叫“紫岳琼台”，下观叫“玉乐霄台”。观之
间借山势起伏修建有多座道院，之间由亭桥相联，故有在三观之间走动“出门
不见天，下雨不湿鞋”的说法，可见琼台是宏大而奇妙的。
LONG
        );

        set("exits", ([
                "eastdown" : __DIR__"langmei",
                "eastup" : __DIR__"gsdao6",
        ]));

        set("no_clean_up", 0);

        set("objects",([
               __DIR__"npc/daotong" : 1,
        ]));

        set("outdoors", "武当");

        setup();
}
