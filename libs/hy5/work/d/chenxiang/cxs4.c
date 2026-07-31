 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "旗场");
        set("long", @LONG
一杆几丈高的木旗杆牢牢地埋在路当中，旗杆的顶端有一个小小
的了望台。这里接近莽林，流匪甚多，每当匪徒来袭扰的时候，衙门
都会从这里观望动向和鸣钟示警。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxs3",
  "west" : __DIR__"yam",
  "east" : __DIR__"fac",
  "south" : __DIR__"cxs5",
  "up" : __DIR__"gding",
]));
        set("outdoors", "chenxiang");
        set("coor/x",-500);
        set("coor/y",-550);
        set("coor/z",0);
        setup();
} 
int valid_leave(object me, string dir)
{
        object room;
        room = find_object(__DIR__"gding");
        if(objectp(room))
        tell_object(room,me->name()+"离开了旗场。\n");
                return 1;
}
int valid_enter(object me, string dir)
{
        object room;
        room = find_object(__DIR__"gding");
        if(objectp(room))
        tell_object(room,me->name()+"来到了旗场。\n");
   return 1;
}  
