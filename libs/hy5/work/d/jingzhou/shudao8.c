// Room: /d/chengdu/shudao8
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR "峭壁" NOR );
        set("long", @LONG
你正爬在一个很危险的峭壁上，你还是快走吧，别一不小心掉了下去。
LONG
        );
        set("exits", ([
  "down" :  __DIR__"shudao7",
  "up" : __DIR__"shudao9",
  
   ]));

        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}

