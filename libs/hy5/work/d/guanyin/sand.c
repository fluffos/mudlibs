 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "迷漫的黄沙中");
        set("long", @LONG
三五人影，似乎正拿着扫把扫地，他们的动作是那么缓慢，却又是
那么的有规律，看来就象是一群没有生命的傀儡，像是恒古以来就在那
时扫着地，一直要扫到世界的末日。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"flower",
  "south" : __DIR__"narrow",
]));
        set("objects", ([
                __DIR__"npc/ghost" : 3,
       ]) ); 
        set("coor/x",-1090);
        set("coor/y",40);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
