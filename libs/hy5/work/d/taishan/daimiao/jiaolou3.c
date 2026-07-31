 //mac's jiaolou3.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","坎角楼");
  set("long",@LONG
这是岱庙围墙四隅的角楼，分别以四卦为名，以求避凶趋吉，楼中
有一面大碑，碑上书一大字：
                                坎
LONG
  );
  set("exits",([
         "south":__DIR__"jiaolou1.c",
         "east" :__DIR__"houzai.c",
               ]));
        set("objects", ([
                __DIR__"npc/gang3" : 1,
                  __DIR__"npc/wolfdog" : 1,
       ]) );
  set("coor/x",300);
        set("coor/y",2360);
        set("coor/z",0);
        setup();
  replace_program(ROOM);
}    
