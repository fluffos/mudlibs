// /d/xingxiu/silk8.c
inherit ROOM;

void create()
{
        set("short", "吐谷浑伏俟城");
        set("long", @LONG
这里是吐谷浑都城。吐谷浑原为鲜卑的一支，游牧于北方。后来首领吐
谷浑率所部西迁于此。以吐谷浑为国名。其可汗现正居于伏俟城内。城内混
居了周围的多个民族，走在大街上看到和听到的无不透着新奇。
LONG);
        set("outdoors", "yili");

        set("exits", ([
                "east" : __DIR__"silk7",
                "west" : __DIR__"bank",
                "northwest" : __DIR__"silk9",
                "south" : __DIR__"nanjiang",
                "north" : __DIR__"silk10",
        ]));

        set("objects", ([
                __DIR__"npc/shangren" : 1,
                __DIR__"npc/bing" : 2,
        ]));

   set("coor/x",-300);
 set("coor/y",110);
   set("coor/z",0);
   setup();
}

#include "/d/xingxiu/job2.h";
