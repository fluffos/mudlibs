#include <ansi.h>
inherit ROOM;

#include "/d/parties/public/du.h";

void create()
{
	set("short", CYN"读书学习室"NOR);
	set("long",  "这里是一处石头砌成的静室，墙上画着几幅图(tu)。\n");
    set("exits", ([
                "northwest": __DIR__"biguanchu",
        ]));
    set("item_desc", ([
        "tu" : "图上是几个小人，作苦读(du)状。\n",
	]));
    set("no_task", 1);
    set("no_reset",1);
    set("no_clean_up", 1);
    setup();
}

