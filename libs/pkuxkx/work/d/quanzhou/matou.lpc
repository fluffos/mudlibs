// created by Zine 2012 for shediao quest
#include <ansi.h>
inherit ROOM;
#include "/d/quanzhou/matou.h"
string look_view();
string look_boat();
void create()
{
	set("short", "太湖码头");
	set("long", "这就是太湖边的一处码头。从这里望去，太湖景色(view)美不胜收。湖边系\n着几条小船(boat)。\n");
	set("exits", ([ 
		"southeast" : __DIR__"river",
		]));
	set("objects", ([
  //__DIR__"npc/ghost" :1,
		]));
	set("item_desc",
        ([
        "view":(:look_view:),
		"boat":(:look_boat:),
        ]));
	set("x",50);
	set("y",-50);
    set("outdoors","quanzhou");
	setup();
}
