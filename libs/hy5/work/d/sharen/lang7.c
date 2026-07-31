 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit ROOM;
void create()
{
        set("short", "≥§¿»");
        set("long", @LONG
≥§¿»
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"qyuan",
  "west" : __DIR__"lang6",

   ]));



        set("objects", ([
       
        __DIR__"npc/bandit1" : 5,
                        ]) );

        set("outdoors", "sharen");
        set("no_death_penalty",1);
        set("coor/y",-450);
        set("coor/z",0);
        set("coor/x",-3);
        setup();
                replace_program(ROOM);

} 