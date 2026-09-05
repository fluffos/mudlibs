// Room: /shenlongjiao/chilongtang.c
// kiden 06/08/27

#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short",HIG"花园"NOR);
        set("long", @LONG
   这是一个小花园，花园中专门开辟了一块花圃，人工种植了一些名贵的奇花异草，神龙教很多珍贵的药丸材料，也是由此而来。
一名弟子在这里浇灌花木。偶尔几只蝴蝶飞来，停在花儿上面。
LONG
        );
        set("outdoors", "shenlongdao");

        set("exits", ([
           "north" : __DIR__"bailongtang",
           "east" : __DIR__"qinglongtang",
           "southeast" : __DIR__"chilongtang",
           "southwest" : __DIR__"heilongtang",           
           "west" : __DIR__"huanglongtang",                                 
           "south" : __DIR__"damen", 
        ]));

   set("objects", ([
         __DIR__"npc/dizi":1,
//        __DIR__"npc/rascal":1,
       ]));
        setup();
        replace_program(ROOM);
}
