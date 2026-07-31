 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "牡丹屋");
        set("long", @LONG
这里都是花，各种各样的花，放都放不下了，只好都排到街边来了。
沉香城的天气一年四季都是那么的好，鲜花都长得特别的旺盛，这里的
花比中原的漂亮多了，而且也便宜多了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"cxs5",
]));
        set("objects", ([
        __DIR__"npc/flowerseller": 1,
                        ]) );
        set("coor/x",-510);
        set("coor/y",-560);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
