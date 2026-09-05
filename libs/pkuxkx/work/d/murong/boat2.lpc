// created by Zine 2012 for shediao quest
#include <ansi.h>
inherit ROOM;
#include "/d/guiyunzhuang/taihu_boat.h"
string look_view();
void create()
{
	set("short", WHT"小船"NOR);
	set("long", "这里是一条小船，没有雨篷，却可以纵览湖中景色(view)。你可以划(hua) \n船前进。\n");
	set("item_desc",
        ([
        "view":(:look_view:),
        ]));
	set("no_task",1);
    //set("outdoors","guiyunzhuang");
	setup();
}
