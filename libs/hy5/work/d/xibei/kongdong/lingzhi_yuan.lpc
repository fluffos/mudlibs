//1997-3-10 by qyz
#include <room.h>

inherit ROOM;



void create()
{
        set("short","灵芝园");
        set("long",@LONG
这里便是灵芝园，园墙中央辟了一个八卦门，门呈八角形，旁列八卦图案，
浮雕松鹤，梅鹿图，墙椽顶上置“双龙戏珠”雕塑，工艺极其精湛，门后刻“
八卦涵宇宙，双龙卫乾坤”一联，园内奇花异草，种类繁多，芳香浓郁，树木
葱荫，是天师散步纳凉休息之所，平时很少有人到这里来。
LONG);
        set("exits",
        ([
          "south" : __DIR__"xuanyuan_gong",
          "north" : __DIR__"lianhua_tai",
         
                ]));
       
        set("outdoors","kongdong");
        set("objects",([
                __DIR__"npc/shouyuan" : 1,
  __DIR__"npc/kdizi1" : 4 ,
                ]) );
        setup();
}
