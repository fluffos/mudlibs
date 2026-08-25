// riverarea.c "小河"
#include <mudlib.h>
#include <ansi.h>
inherit WATER_ROOM;

void setup(){
    set_area("huayin");
    set_light(2);
    set_brief(YEL+"小河"+NOR);
    set_long("\n一条清清的小河。\n\n");

    set_exits( ([
        "north" : __DIR__+"southopen",
    ]) );

    set_enter_msg("south", "$N小心翼翼地走进小河。\n");
    set_exit_msg("north", "$N从小河里走上岸去。\n");
    set_objects( ([
        "/sgdomain/job/fishing/pound" : 1,
       "/sgdomain/job/fishing/yufu" : 1,
	]) );
}
