// mg2.c 迷宫大门
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", CYN "高昌迷宫" NOR);
        set("long", @LONG
你向里面走去，发现迷宫内光线越来越黑，看不清脚下的路。前面好象又
分了几个岔道。
LONG);
        set("no_sleep_room", 1);
        set("exits", ([            
              "south" : __DIR__"mg1",
              "north" : __DIR__"mg4",            
        ]));        
   set("coor/x",-310);
  set("coor/y",170);
   set("coor/z",20);
   setup(); 
}
