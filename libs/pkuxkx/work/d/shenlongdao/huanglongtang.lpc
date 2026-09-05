// Room: /shenlongjiao/huanglongtang.c
// kiden 06/08/27

#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short",YEL"黄龙堂"NOR);
        set("long", @LONG
        这里是神龙教的黄龙堂，堂中香案上供奉着一条黄色神龙，正嘶嘶的吐着信子，冷冷的盯着众人。

LONG
        );
        set("outdoors", "shenlongdao");

        set("exits", ([
           "northeast" : __DIR__"bailongtang",
           "south" : __DIR__"heilongtang",
           "east" : __DIR__"huayuan",  
        ]));

   set("objects", ([
         __DIR__"npc/dizi1":2,
                "/kungfu/class/shenlong/yin" : 1,
//        __DIR__"npc/rascal":1,
       ]));
        setup();
        replace_program(ROOM);
}
