// /u/dubei/miaojiang

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "大门");
        set("long", @LONG
这里是一座红色的大门,上面高悬一块大匾(bian)。五毒教虽然位处于苗疆，
但是其名声早令中原武林谈虎色变。门口的青石台阶上有几名五毒教众把守。
LONG
        );

        set("exits", ([
                "southdown" : __DIR__"slu4",
                "east" : __DIR__"shanya2",
                "north" : __DIR__"qiant",
                
        ]));
        set("item_desc", ([
                 "bian" : HIY "五毒教\n"NOR,
                 ]));
        set("objects",([
                __DIR__"npc/jiaozhong" : 2,

        ]));

       
        set("outdoors", "miaojiang");

        setup();
}
