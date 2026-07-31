 inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
void create()
{
        set("short", "亭顶");
        set("long", @LONG
亭顶积满了青铜锈，非常滑脚。一名白衣人站在顶尖处入神地凝
视远方。他的衣服上披了一层细细的黄沙，似乎赶了很远的路回来。

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" : __DIR__"tongting",
]));
        set("outdoors", "daimiao");
        set("objects", ([
        __DIR__"npc/master" : 1,
                        ]) );
        set("coor/x",310);
        set("coor/y",2350);
        set("coor/z",10);
        setup();
        replace_program(ROOM);
}    
