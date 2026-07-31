 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "沉香城南路");
        set("long", @LONG
这里离沉香台很近，还可以看到竹林的影子。四周都是崭新的，
一看就是刚刚开发出来的地方。往北是老城区，往南则是新建起来
不久的地带。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxcenter1",
  "west" : __DIR__"ch",
  "east" : __DIR__"cag",
  "south" : __DIR__"cxs3",
]));
        set("outdoors", "chenxiang");
        set("coor/x",-500);
        set("coor/y",-530);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
