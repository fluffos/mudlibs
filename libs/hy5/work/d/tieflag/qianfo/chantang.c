 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","禅堂");
  set("long",@LONG
禅堂也称僧堂或云堂，禅僧昼夜于此行道，正中央设文殊师利圣
僧像，此堂与法堂，大殿并称禅宗三大主要建筑。
LONG
  );
  set("exits",([
            "west":__DIR__"mile.c",
               ]));
        set("objects", ([
                __DIR__"npc/bonze3" : 1,
       ]) );
  set("coor/x",60);
        set("coor/y",2060);
        set("coor/z",30);
        setup();
  replace_program(ROOM);
}     
