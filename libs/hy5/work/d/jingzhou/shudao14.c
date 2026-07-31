// Room: /d/chengdu/shudao14
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR "蜀道" NOR );
        set("long", @LONG
你走在以险著称天下的蜀道上，道路十分狭窄，西边有一座高
山。要去成都的话，必须翻过这座高山。四周一片荒凉，渺无人烟。
LONG
        );
        set("exits", ([
  "westup" :  __DIR__"shudao15",
  "southeast" : __DIR__"shudao13",
  
   ]));

        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}

