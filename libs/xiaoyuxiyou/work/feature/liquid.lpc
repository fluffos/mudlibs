// liquid.c
#include <dbase.h>
#include <name.h>
#include <ansi.h>

void init()
{
	if(this_player()==environment())
	{
		add_action("do_drink", "drink");
		add_action("do_fill", "fill");
	}
}

string extra_long()
{
	int amount, max;
	string str;

	if( amount = query("liquid/remaining") ) 
	{
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
	int t;
	mixed err;
	object me = this_player();
	int recover;
	string posion,type,msg = query("drink_msg");

        if( !living(this_player()) || this_player()!=environment() )
		return 0;
	if( !arg || !this_object()->id(arg) ) 
		return 0;
	if( this_player()->is_busy() )
		return notify_fail("你上一个动作还没有完成。\n");
	if( !query("liquid/remaining") ) 
	{
		write( name() + (query("liquid/name") ? "已经被喝得一滴也不剩了。\n":"是空的。\n"));
		return 1;
	}
	if( (int)this_player()->query("water") >= (int)this_player()->max_water_capacity() ) 
	{
		write("你已经喝太多了，再也灌不下一滴水了。\n");
		return 1;
	}
	add("liquid/remaining", -1);
	if(msg) 
	{
		msg=replace_string(msg,"$l",query("liquid/name"));
		message_vision(msg, this_player(), this_object());
	}
	else	message_vision("$N拿起" + name() + "咕噜噜地喝了几口" + query("liquid/name")+ "。\n", this_player());
	t = query("drink_pot");
	if( !t || t<30 )
		t = 30;
	this_player()->add("water", t);
	if( this_player()->is_fighting() ) 
		this_player()->start_busy(1);
	if( !query("liquid/remaining") )
		write("你已经将" + name() + "里的" + query("liquid/name")+ "喝得一滴也不剩了。\n");

	if( query("liquid/drink_func") ) 
	{
		if( functionp(query("liquid/drink_func")) )
		{
        		evaluate( query("liquid/drink_func"),this_player());
        		return 1;
        	}		
		return 1;
	}
	
	switch(query("liquid/type")) 
	{
		case "alcohol":
			this_player()->apply_condition("drunk",(int)this_player()->query_condition("drunk") + (int)query("liquid/drunk_apply"));
			break;
		case "longgong_hot":
			this_player()->apply_condition("longgong_hot", (int)this_player()->query_condition("longgong_hot") +(int)query("liquid/drunk_apply"));
                        break;
		case "longgong_cold":
                        this_player()->apply_condition("longgong_cold",(int)this_player()->query_condition("longgong_cold") +(int)query("liquid/drunk_apply"));
                        break;
		case "ice_poison":
			if( (int)this_player()->query_skill("ningxie-force", 1) < 50 )
				this_player()->apply_condition("ice_poison", (int)this_player()->query_condition("ice_poison") + 2);
                        break;
		case "double_ice_poison":
			if( (int)this_player()->query_skill("ningxie-force", 1) < 100 )
				this_player()->apply_condition("double_ice_poison", (int)this_player()->query_condition("double_ice_poison") + 2);
                        break;
		case "spring": {
			if(me->query_maxkee()>me->query("eff_kee")) 
			{
				recover = (me->query_maxkee()-me->query("eff_kee"))/20;
				if(recover == 0) recover = 1;
				me->receive_curing("kee",recover);
				message_vision("看起来$N的气血恢复了不少。\n",me);
			}
			if(me->query_maxsen()>me->query("eff_sen")) 
			{
				recover = (me->query_maxsen()-me->query("eff_sen"))/20;
				if(recover == 0) recover = 1;
				me->receive_curing("sen",recover);
				message_vision("看起来$N的精神恢复了不少。\n",me);
			}
			break;
			}
		case "回春" :
			if(me->query("eff_kee")>me->query("kee")) 
			{
				recover = (me->query("eff_kee")-me->query("kee"))/25;
				if(recover == 0) recover = 1;
				t = query("drink_pot")/10;
				recover+= t;
				me->receive_heal("kee",t);
				message_vision("$N脸色看起来好了一些。\n",me);
			}
			break;
		case "凝神" :
			if(me->query("eff_sen")>me->query("sen")) 
			{
				recover = (me->query("eff_sen")-me->query("sen"))/25;
				if(recover == 0) recover = 1;
				t = query("drink_pot")/15;
				recover+= t;
				me->receive_heal("sen",t);
				message_vision("$N看起来精神了不少。\n",me);
			}
			break;
		case "吐纳" :
			if(me->query_maxforce()>me->query("force")) 
			{
				recover = (me->query_maxforce()-me->query("force"))/30;
				if(recover == 0) recover = 1;
				t = query("drink_pot")/30;
				recover+= t;
				me->add("force",t);
				message_vision("$N看起来真元恢复了不少。\n",me);
			}
			break;			
		case "归新" :
			if(me->query_maxmana()>me->query("mana")) 
			{
				recover = (me->query_maxmana()-me->query("mana"))/30;
				if(recover == 0) recover = 1;
				t = query("drink_pot")/30;
				recover+= t;
				me->add("mana",t);
				message_vision("$N看起来法力恢复了不少。\n",me);
			}
			break;
		default :
			type = query("liquid/type");
			if( sscanf(type,"conditon_%s",posion)==1 )
			{
				err = catch(me->apply_condition(posion,(int)me->query_condition(posion)+5));
				if( !err )
					write(HIR"你饮用了有毒的"+query("liquid/name")+"，你中毒了！\n"NOR);
			}
			break;					
	}
	
	return 1;
}

int do_fill(string arg)
{
	mapping prop;
	string liquid_name,*types,type;
	string liquid_type,posion;
	
        if( !living(this_player()) || this_player()!=environment() )
		return 0;
	if( !arg || !this_object()->id(arg) ) 
		return 0;
	if( this_player()->is_busy() )
		return notify_fail("你上一个动作还没有完成。\n");
	if( !mapp(prop=environment(this_player())->query("resource")) )	
		return notify_fail("这里没有地方可以装水。\n");
	types = keys(prop);
	type = types[random(sizeof(types))];
	if( !type )
		return notify_fail("这里没有地方可以装水。\n");
	posion = "";	
	switch(type)
	{
		case "spring" : 
			liquid_name = "泉水";
			liquid_type = "spring";
			break;
		case "nuerhong" :
			liquid_name = "女儿红";
			liquid_type = "alcohol";
			break;
		case "double_ice_poison" :
			liquid_type = "double_ice_poison";	
			liquid_name = "清水";
			break;
		case "回春" :
			liquid_type = "回春";	
			liquid_name = "清水";
			break;
		case "凝神" :
			liquid_type = "回春";	
			liquid_name = "清水";
			break;
		case "吐纳" :
			liquid_type = "回春";	
			liquid_name = "清水";
			break;
		case "归新" :
			liquid_type = "回春";	
			liquid_name = "清水";
			break;
		default :
			if( sscanf(type,"conditon_%s",type)==1 )
				posion = type;
			liquid_name = "清水";
			liquid_type = "water";
			break;
	}		
	if( environment(this_player())->query("resource_name") )
		liquid_name = environment(this_player())->query("resource_name");
	if( query("liquid/remaining") )
		message_vision("$N将" + name() + "里剩下的" + query("liquid/name") + "倒掉。", this_player());
	message_vision("$N将" + name() + "装满"+liquid_name+"。\n", this_player());

	if( this_player()->is_fighting() ) this_player()->start_busy(1);
	set("liquid/type", liquid_type);
	set("liquid/name", liquid_name);
	set("liquid/remaining", query("max_liquid"));
	delete("liquid/drink_func");
	if( posion!="" )
		set("liquid/type","condition_"+posion);
	return 1;
}
