// Room: /d/chengdu/shudao19
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN "官道" NOR );
        set("long", @LONG
你走在一条官道上，西面已经可以看见成都城门了，东去是蜀道。
LONG
        );
        set("exits", ([
  "south" :  "/d/chengdu/westgate",
  "east" : __DIR__"shudao18",
  
   ]));
        
        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
	replace_program(ROOM);
}

