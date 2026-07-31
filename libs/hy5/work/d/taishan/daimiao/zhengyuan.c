 //mac's zhengyuan.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","正院");
  set("long",@LONG
这是正院，正面便是天贶殿，又名峻极殿，大中祥符年六月六日，
木匠董裾拾到东岳大帝告真宗的天书，真宗为谢天恩，建此殿。大
殿矗立在一丈高的石砌雕栏平台上，上覆重檐黄色琉璃瓦顶，高大雄
伟，气宇不凡。
LONG
  );
  set("exits",([
         "north":__DIR__"tiankuang.c",
         "south":__DIR__"renan.c",
         "east" :__DIR__"dongbei.c",
         "west" :__DIR__"xibei.c",
               ]));
        set("objects", ([
                __DIR__"npc/daoshi" : 1,
       ]) );
  set("coor/x",310);
        set("coor/y",2320);
        set("coor/z",0);
        setup();
  replace_program(ROOM);
}       
