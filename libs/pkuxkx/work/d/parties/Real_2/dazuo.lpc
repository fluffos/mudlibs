#include <ansi.h>
inherit ROOM;

#include "/d/parties/public/dazuo.h";

void create()
{
	set("short", WHT"打坐吐纳室"NOR);
	set("long",  "这里是一处石头砌成的静室，墙上画着几幅图(tu)。\n");
    set("exits", ([
                "south": __DIR__"biguanchu",
        ]));
    set("item_desc", ([
        "tu" : "图上是几个小人，作打坐(dazuo)、吐纳(tuna)状。\n",
	]));
    set("no_task", 1);
    set("no_reset",1);
    set("no_clean_up", 1);
    setup();
}

