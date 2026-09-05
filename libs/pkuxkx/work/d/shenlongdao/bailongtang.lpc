// Room: /shenlongjiao/bailongtang.c
// kiden 06/08/27

#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short",WHT"白龙堂"NOR);
        set("long", @LONG
        这里是神龙教的白龙堂，堂中香案上供奉着一条白色神龙，正嘶嘶的吐着信子，冷冷的盯着众人。

LONG
        );
        set("outdoors", "shenlongdao");

        set("exits", ([
           "southwest" : __DIR__"huanglongtang",
           "southeast" : __DIR__"qinglongtang",
           "south" : __DIR__"huayuan",  
        ]));

   set("objects", ([
         __DIR__"npc/dizi3":2,
//        __DIR__"npc/rascal":1,
       ]));
        setup();
        replace_program(ROOM);
}
