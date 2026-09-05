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


int do_qu(string arg)
{
    object me=this_player();
    if (!me->query_temp("guche/qu"))
    {
        return 0;
    }
    else
    {
        if (arg=="chengdu"||arg=="成都")
        {
            me->set_temp("guche/target-chengdu",1);
            me->delete_temp("guche/qu");
            tell_object(me,"马车夫道：好嘞，马上就去成都。又快又稳。\n");
            me->apply_condition("mache", 3);
            return 1;
        }
        if (arg=="dali"||arg=="大理")
        {
            me->set_temp("guche/target-dali",1);
            me->delete_temp("guche/qu");
            tell_object(me,"马车夫道：好嘞，马上就去大理。又快又稳。\n");
            me->apply_condition("mache", 4);
            return 1;
        }
        if (arg=="kunming"||arg=="昆明")
        {
            me->set_temp("guche/target-kunming",1);
            me->delete_temp("guche/qu");
            tell_object(me,"马车夫道：好嘞，马上就去昆明。又快又稳。\n");
            me->apply_condition("mache", 4);
            return 1;
        }
        if (arg=="yueyang"||arg=="岳阳")
        {
            me->set_temp("guche/target-yueyang",1);
            me->delete_temp("guche/qu");
            tell_object(me,"马车夫道：好嘞，马上就去岳阳。又快又稳。\n");
            me->apply_condition("mache", 2);
            return 1;
        }
        if (arg=="zhenjiang"||arg=="镇江")
        {
            me->set_temp("guche/target-zhenjiang",1);
            me->delete_temp("guche/qu");
            tell_object(me,"马车夫道：好嘞，马上就去镇江。又快又稳。\n");
            me->apply_condition("mache", 1);
            return 1;
        }
        if (arg=="chengdu"||arg=="应天府")
        {
            tell_object(me,"马车夫道：大爷，你脚下就是应天府了。\n");
            return 1;
        }
        if (arg=="putian"||arg=="莆田")
        {
            me->set_temp("guche/target-putian",1);
            me->delete_temp("guche/qu");
            tell_object(me,"马车夫道：好嘞，马上就去莆田。又快又稳。\n");
            me->apply_condition("mache", 3);
            return 1;
        }
        if (arg=="nanchang"||arg=="南昌")
        {
            
            me->set_temp("guche/target-nanchang",1);
            me->delete_temp("guche/qu");
            tell_object(me,"马车夫道：好嘞，马上就去莆田。又快又稳。\n");
            me->apply_condition("mache", 3);
            return 1;
        }
        else
        {
            tell_object(me,"马车夫面有难色地道：这个地方我没听说过啊。爷，您换个地方吧。\n");
            return 1;
        }
    }
}

