//Cracked by Roath
// fear 2002 1 30
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", CYN"溪边"NOR);
        set("long", @LONG
小溪川流不息，自西向东流来。溪水清澈见底，溪中有几尾小鱼正
无忧无虑的游着。西边可以听见流水声，彷佛是一坐小瀑布，向东走去
就是海岸。
LONG
        );
        set("exits", ([
               "westup" : __DIR__"fall",
               "eastdown" : __DIR__"coast",
        ]));

		set("outdoors", "lingshedao");

		set("cost", 1);
		setup();
		replace_program(ROOM);
}

