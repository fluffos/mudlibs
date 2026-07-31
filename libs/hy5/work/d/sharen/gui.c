 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit ROOM;
void create()
{
        set("short", "衣柜");
        set("long", @LONG
一个檀香大木柜，上层放了些衣服，下层中空，直通地下，
底部黑幽幽一个大洞，似乎可以跳下去。柜子的门半掩着，隐
约听见外面那空灵的女声。仔细往下面看去，洞里一片漆黑，
似乎隐藏着些很重大的机密。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "out" : __DIR__"nroom",
  "down" : __DIR__"andao5",

   ]));



        set("objects", ([
       
//        __DIR__"npc/bandit1" : 5,
                        ]) );

        set("indoors", "sharen");
        set("no_death_penalty",1);
        set("coor/y",395);
        set("coor/z",-1);
        set("coor/x",-5);        
        setup();
                replace_program(ROOM);

} 