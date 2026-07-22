 //      cunluo1.c 藏民部落

#include <ansi.h>

inherit ROOM;


void create()
{
        set("short",NOR"藏民部落"NOR);
        set("long",@LONG 
在这片宽广的草原上有几个帐篷，原来是几户靠游牧为生的藏民。他们通
常由几户到上百户不等，组成部落，由部落头人带领，逐水草而居，居无定所，
游牧四方。性格一般大都粗犷豪放，非常好客。
LONG);
        set("exits",([
                "north" : __DIR__"cunluo2",  
                "westup" : __DIR__"caishichang",
                "west" :__DIR__"muchang3",
                "east" :__DIR__"muchang7"
        ]));
        set("objects", ([__DIR__"npc/mumin" : 1,]));
        set("coor/x",-200);
  set("coor/y",150);
   set("coor/z",-10);
   setup();
}
