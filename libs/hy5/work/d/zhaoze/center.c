 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit ROOM;
void create()
{
        set("short", "火沼中心");
        set("long", @LONG
一潭黑水不停地冒着气泡，枯枝烂叶连同发黄的白骨足有尺厚。
几块暗红色的狰狞巨石堆在黑水中央，上面布满了各种尸骸。潭水
中漂浮着段段枯木，有些还散发着袅袅黑烟。
LONG
        );
        set("exits", ([ 
                 "west" : __DIR__"zhaoze4",
]));
        set("objects", ([
                __DIR__"npc/dragon" : 1,
       ]) );
        set("outdoors", "zhaoze");
//      set("no_curse",1);
        set("coor/x",-520);
        set("coor/y",-650);
        set("coor/z",-20);
        setup();
        replace_program(ROOM);
}  
