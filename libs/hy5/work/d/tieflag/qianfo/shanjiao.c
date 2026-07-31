 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","千佛山角");
  set("long",@LONG
千佛山，又名历山，是中国佛教名山之一，从此向东眺望，
一座青山耸立，南北向绵延不绝，山腰处隐约可见几间瓦房，在
青松翠柏的掩映下格外超凡脱俗。西边是一条阳关大道，北边是
连绵起伏的舜耕山。
LONG
  );
  set("exits",([
         "east" :__DIR__"tanghuai.c",
         "west" :__DIR__"road1.c"
               ]));
        set("objects", ([
                __DIR__"npc/bonze" : 1,
       ]) );
        set("outdoors", "qianfo");
  set("coor/x",20);
        set("coor/y",2000);
        set("coor/z",0);
        setup();
  replace_program(ROOM);
}
