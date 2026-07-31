 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit ROOM;
void create()
{
        set("short", "暗道");
        set("long", @LONG
地穴中伸手不见五指，这死般的寂静，令一切都显得到
更可怖。石壁凹入了一块，似乎是个标记，摸着这个标记，
似乎一直指向前面。眼前这片无边的黑暗到底隐藏着什么？ 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"andao1",
  "east" : __DIR__"andao3",
  "south" : __DIR__"andao4",
  "north" : __DIR__"andao4",

   ]));



        set("objects", ([
       
//        __DIR__"npc/bandit1" : 5,
                        ]) );

        set("indoors", "sharen");
        set("no_death_penalty",1);
        set("coor/y",-430);
        set("coor/z",-5);
        set("coor/x",-8);
        setup();
} 