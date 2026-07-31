// Room: /d/chengdu/sanxia2
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY "巫峡" NOR );
        set("long", @LONG
这里是长江三峡的巫峡，也是最大最美的一个峡谷，神女峰
高高耸立在江边，远远看去，由如一为亭亭玉立的少女，两岸风
景美不胜收。
LONG
        );
        set("exits", ([
  "northeast" :  __DIR__"sanxia1",
  "northwest" : __DIR__"sanxia3",
  
   ]));
//        set("no_fight",1);

        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}

