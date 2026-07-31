// Room: /d/chengdu/shudao18
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR "蜀道" NOR );
        set("long", @LONG
你走在以险著称天下的蜀道上，西面不远，就到成都了，向东
则开始走入险恶的蜀道。
，
LONG
        );
        set("exits", ([
  "west" :  __DIR__"shudao19",
  "eastup" : __DIR__"shudao17",
  
   ]));
        
        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
	replace_program(ROOM);
}

