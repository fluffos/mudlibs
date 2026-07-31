 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "玄武门");
        set("long", @LONG
沉香城虽然刚刚初具规模，但该有的都已经有了。此门虽然只是
装饰所用，但上面飞檐镂砖，再加上一层翠绿的青苔，偶尔还有小巧
的鸟儿在此驻足。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxs2",
  "west" : __DIR__"mw",
  "east" : __DIR__"me",
  "south" : __DIR__"cxs4",
]));
        set("outdoors", "chenxiang");
        set("coor/x",-500);
        set("coor/y",-540);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}      
