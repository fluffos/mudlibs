// Room: /d/chengdu/shudao11
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR "蜀道" NOR );
        set("long", @LONG
你走在以险著称天下的蜀道上，从这里向西越过高山，就进入
四川盆地，东边，是去风景优美的三峡。道路十分崎岖，时而左转
时而上山，时而又要穿过森林。
LONG
        );
        set("exits", ([
  "east" :  __DIR__"sanxia3",
  "northwest" : __DIR__"shudao12",
  
   ]));

        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}

