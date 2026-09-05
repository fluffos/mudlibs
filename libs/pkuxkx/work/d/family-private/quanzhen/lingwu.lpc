#include <ansi.h>
inherit F_SAVE;
inherit ROOM;
string query_save_file()
{
        return "/data/home/private_area/"+this_object()->query("family");
}
#include "/d/family-private/lingwu.h";

void create()
{
	set("short", WHT"石室"NOR);
	set("long",  "这里是一处石头砌成的静室，墙上画着几幅图(tu)。\n");
    set("exits", ([
                "east": __DIR__"biguanchu",
        ]));
    set("item_desc", ([
        "tu" : "图上是几个小人，作领悟(lingwu)武功状。作为本派弟子可以用门忠增长(develop)这里的功能。\n",
	]));
    set("family_private_area",1);
    set("no_task", 1);
    setup();
    restore();
    call_out("rebuild",1);
    call_out("get_lv",1);
}

