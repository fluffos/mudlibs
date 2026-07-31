// senlin.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short","针叶林");
        set("long", @LONG
这是极西天山脚下的一片针叶林，林中鸟兽成群，满地铺盖着厚厚一层松
针。西北方的一座高耸的山脉便是天山了，山上终年积雪，山下却是绿树成荫。
往东南走便是大草原，有辛勤的哈萨克族人在那里放牧。
LONG
       );

        set("exits", ([
                "northwest" : "/d/xingxiu/tianshan",
                "northeast" : "/d/xingxiu/shanjiao",
                "southeast" : __DIR__"shanqiu",
        ]));
        
        set("objects", ([
                         __DIR__"npc/bird" : 1,
        ]));

        set("outdoors", "天山");

        set("coor/x",-310);
  set("coor/y",110);
   set("coor/z",0);
   setup();
}
