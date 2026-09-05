// Room: /shenlongjiao/chilongtang.c
// kiden 06/08/27

#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short",RED"赤龙堂"NOR);
        set("long", @LONG
        这里是神龙教的赤龙堂，堂中香案上供奉着一条赤色神龙，正嘶嘶的吐着信子，冷冷的盯着众人。

LONG
        );
        set("outdoors", "shenlongdao");

        set("exits", ([
           "north" : __DIR__"qinglongtang",
           "west" : __DIR__"damen",
           "northwest" : __DIR__"huayuan",  
        ]));

   set("objects", ([
         __DIR__"npc/nvdizi":2,
                "/kungfu/class/shenlong/wugen" : 1,
//        __DIR__"npc/rascal":1,
       ]));
        setup();
        replace_program(ROOM);
}
