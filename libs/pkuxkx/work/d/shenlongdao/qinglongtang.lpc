// Room: /shenlongjiao/qinglongtang.c
// kiden 06/08/27

#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short",CYN"青龙堂"NOR);
        set("long", @LONG
        这里是神龙教的青龙堂，堂中香案上供奉着一条青色神龙，正嘶嘶的吐着信子，冷冷的盯着众人。

LONG
        );
        set("outdoors", "shenlongdao");

        set("exits", ([
           "northwest" : __DIR__"bailongtang",
           "south" : __DIR__"chilongtang",
           "west" : __DIR__"huayuan",  
        ]));

   set("objects", ([
         __DIR__"npc/dizi4":2,
                "/kungfu/class/shenlong/xu" : 1,
//        __DIR__"npc/rascal":1,
       ]));
        setup();
        replace_program(ROOM);
}
