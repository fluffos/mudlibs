 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "老城东街");
        set("long", @LONG
这里的街道显得比较荒芜。一条小溪顺着街北静静地流淌，每当太阳
落山，一阵阵的浓雾便从东面的莽林渗来，渐渐地将整个沉香城吞没在烟
雾迷漫之中。直到第二天太阳高照，浓雾才渐渐散去。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"cxe2",
  "west" : __DIR__"cxcenter",
]));
        set("outdoors", "chenxiang");
        set("coor/x",-490);
        set("coor/y",-500);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
