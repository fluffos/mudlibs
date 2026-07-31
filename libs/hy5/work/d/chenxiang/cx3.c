 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "老北街");
        set("long", @LONG
暗青色的石砖，四轮马车宽的街道，你似乎还可以看到当年小镇的
影子。除了一切都变得陈旧以外，别的什么都没有变。西面的中药店已
经今非昔比，生意好的不得了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"cx2",
  "southeast" : __DIR__"cx4",
  "west" : __DIR__"yao",
]));
        set("outdoors", "chenxiang");
        set("coor/x",-510);
        set("coor/y",-480);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
