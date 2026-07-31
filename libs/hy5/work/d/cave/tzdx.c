 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "天中道西");
        set("long", @LONG
这里是个丁字路口，东面的叉口直接通到天外天的中心，
从这里就可以看到中心的园坛。在白天的时候还可以看到从洞
顶圆洞直射下来的圆柱。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"btxl",
  "south" : __DIR__"ntxl",
  "east" : __DIR__"zdxm",
]));
        set("indoors", "cave");
        set("coor/x",-60);
        set("coor/y",-30);
        set("coor/z",-20); 
        setup();
}  
