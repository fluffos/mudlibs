 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "草地");
        set("long", @LONG
庭园深深，夜色如墨，似乎到处都是人影。只觉得风吹树叶，
连大地也在低沉地呻吟。前面厢房木窗的裂缝里，已透出灰蒙蒙的
灯光，门犹在不住摇蔽。林木间左转右转，就来到一座假山，从假
山的中间穿过去，则是一座鬼气森森的楼阁。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"guan",
  "east" : __DIR__"hyuan",

   ]));



        set("objects", ([
       
        __DIR__"npc/bandit1" : 1,
        __DIR__"npc/bandit2" : 1,
        __DIR__"npc/bandit3" : 1,
        __DIR__"npc/bandit4" : 1,
        __DIR__"npc/bandit5" : 1,
                        ]) );

        set("outdoors", "sharen");
        set("no_death_penalty",1);
        set("coor/y",-430);
        set("coor/z",0);
        set("coor/x",-15);
        setup();
        create_door("west", "青铜门", "east", DOOR_CLOSED); 
} 