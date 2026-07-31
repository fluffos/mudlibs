 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit ROOM;
void create()
{
        set("short", "长廊");
        set("long", @LONG
典型江南风格的雕花长廊造工非常精致，不过可
惜此刻铺满了灰尘和蛛网。长廊边上的廊栏还有不少
刀砍剑刻的痕迹，正是这里终年打斗的结果。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"lang4",
  "southeast" : __DIR__"lang6",

   ]));



        set("objects", ([
       
        __DIR__"npc/bandit1" : 5,
                        ]) );

        set("outdoors", "sharen");
        set("no_death_penalty",1);
        set("coor/y",-450);
        set("coor/z",0);
        set("coor/x",-8);
        setup();
                replace_program(ROOM);

} 