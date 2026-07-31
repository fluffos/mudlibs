// Room: /d/chengdu/shudao6
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR "栈道" NOR );
        set("long", @LONG
蜀道难，难于上青天，呜呼，无怪李白如此写。路到了这里真可
谓惊险无比，一边是滔滔的江水，一边是如刀切般的峭壁，朝西已无
路可走，只有峭壁上有一些石窝，可以攀登而上，向东，却是摇摇晃
晃的栈道。 
LONG
        );
        set("exits", ([
  "east" :  __DIR__"shudao6",
  "up" : __DIR__"shudao8",
  
   ]));

        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}

