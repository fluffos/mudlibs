// Zine 马车 NOV28 2010
inherit ROOM;
#include <ansi.h>
#include "dache.h"


void create()
{
	set("short", "马车车厢");
	set("long", @LONG
一辆内饰华丽的马车，车厢内有个小桌(desk)，周围吃的用的一应俱全。
LONG
	);
    set("item_desc", ([
		"desk" : "桌上放了一瓶冰镇的竹叶青，你可以喝(drink)，还有许多食物，你可以自行取用(na)。\n", 
	]));

	set("no_task",1);
    set("real_dark",1);
	setup();
	
}



int do_qu(object me)
{
            me->set_temp("guche/target-riyuejiao",1);
            tell_object(me,"马车夫道：过一会就可以到日月神教了。不要着急。\n");
            me->apply_condition("mache", 4);
            return 1;

}

