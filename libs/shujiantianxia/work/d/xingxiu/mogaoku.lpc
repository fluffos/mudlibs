// /d/xingxiu/mogaoku.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"莫高窟"NOR);
        set("long", @LONG
这里是敦煌莫高窟，窟内墙壁上绘制着与佛教相关的画面，有仙女飞天，
还有反弹琵琶。洞中还有很多佛像和经书。你被这些瑰丽的文化之宝惊呆了。
LONG);
        set("exits", ([ 
             "out" : __DIR__"silk3c",
        ]));

         set("objects", ([
                "/d/shaolin/obj/fojing11" : 1,
                "/d/shaolin/obj/fojing20" : 1,
                "/d/shaolin/obj/fojing21" : 1,
        ]));

        setup();
}

