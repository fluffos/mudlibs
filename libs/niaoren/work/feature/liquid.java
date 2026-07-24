// liquid.c

#include <dbase.h>
#include <name.h>

void init()
{
	add_action("do_drink", "he");
	add_action("do_drink", "drink");
	add_action("do_fill", "fill");
	add_action("do_fill", "zhuang");
}

string extra_long()
{
	int amount, max;
	string str;

	if( amount = query("liquid/remaining") ) {
		max = query("max_liquid");
		if( amount == max )
			str = "里面裝滿了" + query("liquid/name") + "。\n";
		else if( amount > max/2 )
			str = "里面裝了七、八分滿的" + query("liquid/name") + "。\n";
		else if( amount >= max/3 )
			str = "里面裝了五、六分滿的" + query("liquid/name") + "。\n";
		else if( amount > max/2 )
			str = "里面裝了少許\的" + query("liquid/name") + "。\n";
		return str;
	}
	else return 0;
}

int do_drink(string arg)
{
	if( !this_object()->id(arg) ) return 0;
	if( this_player()->is_busy() )
		return notify_fail("你上一個動作還沒有完成。\n");
	if( !query("liquid/remaining") )
		return notify_fail( name() + (query("liquid/name") ? "已經被喝得一滴也不剩了":"是空的。\n"));
	if( (int)this_player()->query("water") >= (int)this_player()->max_water_capacity() )
		return notify_fail("你已經喝太多了，再也灌不下一滴水了。\n");

	add("liquid/remaining", -1);
	message_vision("$N拿起" + name() + "咕嚕嚕地喝了几口" + query("liquid/name")
		+ "。\n", this_player());
	if( query("liquid/supply") >0 )
		this_player()->add("water", query("liquid/supply"));
	else
		this_player()->add("water", 30);
	if( query("liquid/poisontime") > 1 )
	{
		this_player()->apply_condition(query("liquid/poison"),query("liquid/poisontime") );
		write("你突然覺得喝的東西有點不對勁。可已經來不及了。\n");
	}
	if( this_player()->is_fighting() ) this_player()->start_busy(2);
	if( !query("liquid/remaining") )
		write("你已經將" + name() + "里的" + query("liquid/name")
			+ "喝得一滴也不剩了。\n");

	// This allows customization of drinking effect.
	if( query("liquid/drink_func") ) return 1;

	switch(query("liquid/type")) {
		case "alcohol":
			this_player()->apply_condition("drunk",
				(int)this_player()->query_condition("drunk") 
				+ (int)query("liquid/drunk_apply"));
			break;
	}
	
	return 1;
}

int do_fill(string arg)
{
	if( !this_object()->id(arg) ) return 0;
	if( this_player()->is_busy() )
		return notify_fail("你上一個動作還沒有完成。\n");
	if( !environment(this_player())->query("resource/water") )
		return notify_fail("這里沒有地方可以裝水。\n");

	if( query("liquid/remaining") )
		message_vision("$N將" + name() + "里剩下的" + query("liquid/name") + "倒掉。\n", this_player());
	message_vision("$N將" + name() + "裝滿清水。\n", this_player());

	if( this_player()->is_fighting() ) this_player()->start_busy(2);

	set("liquid/type", "water");
	set("liquid/name", "清水");
	set("liquid/remaining", query("max_liquid"));
	set("liquid/drink_func", 0);

	return 1;
}
