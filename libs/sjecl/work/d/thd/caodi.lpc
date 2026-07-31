// Room: /u/numa/thd/caodi.c
// Modified by Numa 19980903

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN"草地"NOR);
        set("long",@LONG
一片绿油油的草地映入你的眼帘，你顿时感到周围笼罩着一股清新的气氛。
西面有一座桐木搭成的亭子，北面满是竹林密布，而东面则是一条光秃秃的
山路，看不清究竟通向哪里。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "eastup" : __DIR__"shanjiao",
                "west" : __DIR__"shijian-ting",
                "south" : __DIR__"shangang",
                "north" : __DIR__"zhulin1",
        ]) );
        set("no_clean_up", 0);
        set("outdoors","桃花岛");

        setup();
}

