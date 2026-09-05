// liquid.c
// Modified by iszt@pkuxkx, 2007-05-21

#include <dbase.h>
#include <name.h>

void init()
{
    object me = this_player();
    if( environment() == me || me->query("env/food"))
    {
        add_action("do_drink", "he");
        add_action("do_drink", "drink");
        add_action("do_fill", "fill");
        add_action("do_fill", "zhuang");        
    }
}

string extra_long()
{
	int amount, max;
	string str;

	if( amount = query("liquid/remaining") ) {
		max = query("max_liquid");
		if( amount == max )
			str = "里面装满了" + query("liquid/name") + "。\n";
		else if( amount > max/2 )
			str = "里面装了七、八分满的" + query("liquid/name") + "。\n";
		else if( amount >= max/3 )
			str = "里面装了五、六分满的" + query("liquid/name") + "。\n";
		else if( amount > max/2 )
			str = "里面装了少许的" + query("liquid/name") + "。\n";
		return str;
	}
	else return 0;
}

int do_drink(string arg)
{
	object me = this_player();
	object obj = this_object();

	if( !obj->id(arg) ) return 0;
	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成。\n");
	if( !query("liquid/remaining") )
                return notify_fail( name() + (query("liquid/name") ? "已经被喝得一滴也不剩了。\n":"是空的。\n"));
	if( (int)me->query("water") >= (int)me->max_water_capacity() )
		return notify_fail("你已经喝太多了，再也灌不下一滴水了。\n");




	add("liquid/remaining", -1);
	if((string)obj->query("drink_msg"))
		message_vision(obj->query("drink_msg"), me, obj);
	else
		message_vision("$N拿起$n咕噜噜地喝了几口" + obj->query("liquid/name")+ "。\n", me, obj);
	me->add("water", 30);

	// 喝水可以提供短时buff效果. lordstar 20180423
	// 函数定义在 inherit/char/char.c
	me->apply_liquid_effect(obj);

	if( me->is_fighting() ) me->start_busy(2);
	if( !query("liquid/remaining") )
	{
		if((string)obj->query("finish_msg"))
			write(obj->query("finish_msg"));
		else
			write("你已经将" + obj->name() + "里的" + obj->query("liquid/name")+ "喝得一滴也不剩了。\n");
	}

	// This allows customization of drinking effect.
	if( query("liquid/drink_func") ) return 1;

	switch(query("liquid/type")) {
		case "alcohol":
			me->apply_condition("drunk",
				(int)me->query_condition("drunk") 
				+ (int)query("liquid/drunk_apply"));
			break;
	}
	
	return 1;
}

int do_fill(string arg)
{
	object me = this_player();
	object obj = this_object();

	if( !obj->id(arg) ) return 0;
	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成。\n");
	if( !environment(me)->query("resource/water") )
		return notify_fail("这里没有地方可以装水。\n");

	if( query("liquid/remaining") )
		message_vision("$N将" + name() + "里剩下的" + query("liquid/name") + "倒掉。\n", me);
	message_vision("$N将" + name() + "装满清水。\n", me);

	if( me->is_fighting() ) me->start_busy(2);

	set("liquid/type", "water");
	set("liquid/name", "清水");
	set("liquid/remaining", query("max_liquid"));
	set("liquid/drink_func", 0);

	return 1;
}
