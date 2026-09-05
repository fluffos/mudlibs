// Zine 马车 NOV28 2010
inherit ROOM;
#include <ansi.h>



void create()
{
	set("short", "马车车厢");
	set("long", @LONG
一辆内饰华丽的马车，车厢内有个小桌(desk)，周围吃的用的一应俱全。
LONG
	);
    set("item_desc", ([
		"desk" : "桌上放了一锅鸡汤，你可以喝(drink)。\n", 
	]));

	set("no_task",1);
    set("real_dark",1);
	setup();
	
}

int do_drink(string arg)
{
        int current_water;
        int max_water;
        object me;
        me = this_player();
        if(arg)
                return 0;
        current_water = me->query("water");
        max_water = (int)me->max_water_capacity();
        if (current_water<max_water) {
                me->add("water", 450);
                me->add("food",20);
                tell_object(me,"你端起桌上的鸡汤，一口喝了下去。\n");
        }
        else tell_object(me,"你已经喝饱了，一滴也喝不下去了。\n");

        return 1;
}