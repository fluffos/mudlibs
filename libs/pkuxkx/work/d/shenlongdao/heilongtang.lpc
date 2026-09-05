// Room: /shenlongjiao/heilongtang.c
// kiden 06/08/27

#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short",WHT"黑龙堂"NOR);
        set("long", @LONG
        这里是神龙教的黑龙堂，堂中香案上供奉着一条黑色神龙，正嘶嘶的吐着信子，冷冷的盯着众人。

LONG
        );
        set("outdoors", "shenlongdao");

        set("exits", ([
           "east" : __DIR__"damen",
           "north" : __DIR__"huanglongtang",
           "northeast" : __DIR__"huayuan",  
        ]));

   set("objects", ([
         __DIR__"npc/dizi2":2,
                "/kungfu/class/shenlong/zhang" : 1,
//        __DIR__"npc/rascal":1,
       ]));
        setup();
        replace_program(ROOM);
}
