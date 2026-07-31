 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "花海");
        set("long", @LONG
放眼望去，但见天地间仿佛已被鲜花充满，但却是无人认得出的花
朵，只觉得这些花无比的鲜艳，无比的美丽。真是令人想不到，荒漠之
中，竟有这样的花海。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"valley",
        ]));
        set("objects", ([
                __DIR__"npc/qu" : 1,
                __DIR__"npc/ji" : 1,
       ]) );
        set("outdoors", "fengyun");
        set("coor/x",-1090);
        set("coor/y",70);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
