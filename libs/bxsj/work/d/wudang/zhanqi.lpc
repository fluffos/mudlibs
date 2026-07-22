// /area/jiangbei/wudang/zhanqi.c 展旗峰
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", WHT"展旗峰"NOR);
        set("long", @LONG
展旗峰为武当的中心山峰，峰奇峦秀，涧险岩危，自古就被誉为“天下第
一仙峰”。其形威峻极，上接青天，下临深谷，犹如展开的大旗一般，故得此
名。展旗峰前接下山古神道，山下坐落着紫霄宫，半山腰还有著名的雷神洞，
大部分武当弟子的活动在此峰之上。
LONG
        );

        set("exits", ([
                "northdown" : __DIR__"shijie2",
                "west" : __DIR__"gsdao3",
                "southup" : __DIR__"shijie3",
        ]));

        set("no_clean_up", 0);

        set("outdoors", "武当");

        setup();
}
