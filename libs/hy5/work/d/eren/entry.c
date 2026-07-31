 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
        set("short","石壁");
        set("long","一堵很高的石壁，上面爬满青藤，石壁上有一扇小门。\n");
        set("exits",([
//               "south":__DIR__"qianyuan.c",
               ]));
        set("objects", ([
                __DIR__"obj/stonedoor" : 1,
/*              __DIR__"obj/heart":1,
                __DIR__"obj/liver":1,
                __DIR__"obj/stomach":1,
                __DIR__"obj/lung":1,
                __DIR__"obj/kidney":1,*/
        ]) );
        set("item_desc", ([
                "mark": "你似乎可以将内力从掌印输入（ｔｏｕｃｈ）铜人体内。\n",
                "掌印" : "你似乎可以将内力从掌印输入（ｔｏｕｃｈ）铜人体内。\n", 
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}
