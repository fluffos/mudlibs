 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit ROOM;
void create()
{
        set("short", "杀人庄");
        set("long", @LONG
山庄前院里堆满了人，各地的通缉犯、杀人犯、名门正派的叛徒等
等，几乎全部云集于此。虽然在这里人命如草，但这些亡命之徒也知道，
最危险的地方也是最安全的地方，因为他们的对头人未必敢进来这个见
人就杀的山庄。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"zmen",
  "west" : __DIR__"juyitang",
  "northwest" : __DIR__"lang1",
  "southwest" : __DIR__"lang7",

   ]));



        set("objects", ([
       
        __DIR__"npc/bandit1" : 2,
        __DIR__"npc/bandit2" : 2,
        __DIR__"npc/bandit3" : 2,
                        ]) );

        set("outdoors", "sharen");
        set("no_death_penalty",1);
        set("coor/y",-430);
        set("coor/z",0);
        set("coor/x",3);
        setup();
                replace_program(ROOM);

} 