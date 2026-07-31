 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit ROOM;
void create()
{
        set("short", "暗道");
        set("long", @LONG
地穴方圆有两丈，除了眼前这名老人家外，竟还有张小床，床边有
个小小的木柜，上面零乱的放着些杯壶、书册，灰尘已积了半寸。这些
虽都是些平常的日用之物，但在这无人的秘穴里发现这些东西，却硬显
得说不出的神秘。书册里夹着几张素笺，上面写着的竟是些艳语绮词，
而且看似女子的手笔。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"andao2",
  "north" : __DIR__"andao4",

   ]));



        set("objects", ([
       
        __DIR__"npc/guo" : 1,
                        ]) );

        set("indoors", "sharen");
        set("no_death_penalty",1);
        set("coor/y",-430);
        set("coor/z",-5);
        set("coor/x",-5);
        setup();
} 