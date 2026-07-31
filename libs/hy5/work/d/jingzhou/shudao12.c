// Room: /d/chengdu/shudao12
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR "蜀道" NOR );
        set("long", @LONG
你走在以险著称天下的蜀道上，道路十分狭窄，这里不时会有
强盗出没，来往的人很少，举目看去，方圆几百里内没有人烟，你
还是加快步子走吧。
LONG
        );
        set("exits", ([
  "southeast" :  __DIR__"shudao11",
  "southwest" : __DIR__"shudao13",
  
   ]));

        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}

