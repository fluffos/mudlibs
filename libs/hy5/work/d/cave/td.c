 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "小土洞");
        set("long", @LONG
说是个土洞，其实就是甬道旁边再挖进去一块，如果说
甬道象一条胡同，这小土洞就是胡同旁边的一个小土屋。土洞
不大，里面有一张桌子和一张小床，看起来就象个哨卡。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"yd",
  "south" : __DIR__"twt",
]));
        set("objects", ([
        __DIR__"obj/bed": 1,
        __DIR__"obj/desk": 1,
        __DIR__"npc/maoye": 1,
                        ]) );
        set("indoors", "cave");
        set("coor/x",-45);
        set("coor/y",5);
        set("coor/z",-20);
        setup();
        replace_program(ROOM);
} 
