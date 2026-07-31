 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "南天东路");
        set("long", @LONG
虽然是地下，这里居然还有一些景色可言。路边长着一种非
木非草的植物，好象是巨大的蘑菇，但又闪着紫色的光芒。还有
一种特别象竹子的植物，也是灰紫色的。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"ztdd",
  "south" : __DIR__"ntdm",
]));
        set("coor/x",-30);
        set("coor/y",-20);
        set("coor/z",-20);
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//      __DIR__"npc/fishbuyer": 1,
//                        ]) );
        setup(); 
}  
