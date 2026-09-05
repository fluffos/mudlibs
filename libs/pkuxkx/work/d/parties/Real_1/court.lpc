#include <ansi.h>
inherit ROOM;
#include "/d/parties/public/court.h";

string look_bei();
void create()
{
	set("short", HIG"庭院"NOR);
	set("long",  "这里是一处庭院，中间立着一块石碑(bei)。\n");
    set("exits", ([
                "west": __DIR__"biguanchu",
        ]));
    set("item_desc", ([
        "bei" : (:look_bei:),
	]));
    set("no_task", 1);
    set("no_reset",1);
    set("no_clean_up", 1);
	set("loc_cmds",(["do_write":"write","do_gua":"gua","do_gua":"guashang","do_zhai":"zhai"]));
    setup();
}
