//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIG"草地"NOR);
        set("long", @LONG
    这里是一遍绿茵茵的草地，像是一方绿色的毯子铺在地上。草丛中
开着一些不知名的小花，有红的、黄的，还有紫的。花瓣上、草叶上的
露珠闪着晶莹的光。
LONG
        );
        set("no_task",1);
        set("exits", ([
                "southeast" : __DIR__"danjiangkou",
                "north" : __DIR__"caodi2",
        ]));

        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}

