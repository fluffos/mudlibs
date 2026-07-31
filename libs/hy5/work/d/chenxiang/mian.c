 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "小面馆");
        set("long", @LONG
这么多年，小面馆的阵设几乎一成不变，肮脏而且很简陋。当年的卖
面老人已经不在了，换了个年轻人。面馆除了中午和晚上卖面之外也卖一
些很简单的旱点。有一种很油腻的韭菜合子，不是肠胃特别好的人，很难
消化得了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"cx1",
]));
        set("objects", ([
        __DIR__"npc/youngman": 1,
         __DIR__"npc/linshouou" : 1,
                        ]) );
        set("coor/x",-520);
        set("coor/y",-460);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
