//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "大官道");
        set("long", @LONG
这是一条宽阔笔直，尘土飞扬的大官道，足可容得下十马并驰。往东
通向虎牢关可以达扬州城，西边便是洛阳的城东桥。
LONG
        );

        set("exits", ([
               "westup" : __DIR__"chengdongqiao",
               "east" : __DIR__"guandao5",

        ]));
        set("objects", ([
              __DIR__"npc/randomnpc" : 1,
           ]));


        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}
