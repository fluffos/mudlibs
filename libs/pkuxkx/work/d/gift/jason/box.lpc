#include <ansi.h>

inherit F_SAVE;

inherit ITEM;

void restore_eggs();

string query_save_file()
{
	return "/data/gift/box";
}

void create()
{
	object* obs;

	
    set_name(YEL"鸡窝"NOR, ({ "ji wo",}));
    set_weight(6000);
    set("unit", "个");
	set_max_encumbrance(2000000);
    set("long","这是一个普通的鸡窝，用竹条和草编织的。\n");
	set("material", "wood");
	set("no_sell",1);
	set("eggs",0);
	set("value",1); 
	if(sizeof(filter_array(children(__DIR__"box"), (:clonep:))) > 1) 
	{
		set_name(HIG"破鸡窝"NOR, ({ "ji wo",}));
		set("long","一个破烂的鸡窝，没什么用了。\n");
		set_temp("po",1);
	}
	else
	{
		restore();
		restore_eggs();
	}
}

void restore_eggs()
{
	int i;
	object egg;
	object* inv;
	int num = query("eggs");
	inv = all_inventory();
	for(i=0;i<sizeof(inv);i++)
	{
		if(!userp(inv[i])) destruct(inv[i]);
	}
	for(i=0;i<num;i++)
	{
		egg = new(__DIR__"egg");
		egg->move(this_object());
	}
}

void init()
{
	add_action("do_put","put");
	add_action("do_get","get");
	add_action("do_fu","fu");
}

int do_get(string arg)
{
	string item,target;
	if(query_temp("po")) return 0;
	
	if(this_player()->is_busy())
	{
		write("你正忙着呢。\n");
		return 1;
	}
	if( sscanf(arg, "%s from %s", item, target) ==2 && (item == "egg" || item == "ji dan" || item == "dan") && target == "ji wo") 
	{
		if(query("eggs") > 0)
		{
			if(call_other(load_object("/cmds/std/get"),"main",this_player(),arg) > 0)
			{
				add("eggs",-1);
				save();
			}
			return 1;
		}
		else
		{
			write("鸡窝里没有鸡蛋了！\n");
			return 1;
		}
	}
	else if(sscanf(arg, "%s from %s", item, target) ==2 && (item != "egg" && item != "ji dan" && item != "dan"))
	{
		write("鸡窝里除了鸡蛋还能有别的吗！？\n");
		return 1;
	}

	return 0;
}

int do_put(string arg)
{
	string item,target;
	if(query_temp("po")) return 0;

	if( sscanf(arg, "%s in %s", item, target) ==2 && (item == "egg" || item == "ji dan" || item == "dan") && target == "ji wo") 
	{
		if(query("eggs") < 20)
		{
			if(call_other(load_object("/cmds/std/put"),"main",this_player(),arg) > 0)
			{
				add("eggs",1);
				save();
			}
			return 1;
		}
		else
		{
			write("鸡窝已经满了，放不下了！\n");
			return 1;
		}
	}
	else if((item != "egg" && item != "ji dan" && item != "dan"))
	{
		write("鸡窝里不要放其他的东西！\n");
		return 1;
	}

	return 0;
}

int do_fu(string arg)
{
	object egg;
	object* inv;
	object chick;
	int i ;
	inv = all_inventory();
	if(query_temp("po")) return 0;
	if(this_player()->is_busy()) return notify_fail("你正忙着呢。\n");
	if(query("eggs") < 1) 
	{
		write("鸡窝里什么都没有，孵什么蛋！\n");
		return 1;
	}
	if(environment() != this_player())
	{
		write("你离鸡窝那么远，怎么孵蛋？拿起来吧.\n");
		return 1;
	}
	message_vision("$N蹲下来，小心的用屁股捂住鸡窝，嘴里发出咯咯咯咯咯的声音。\n",this_player());
	for(i=0;i<sizeof(inv);i++)
	{
		if(inv[i]->isegg())
		{
			if(random(10) == 0)
			{
				inv[i]->add("time",1);
				inv[i]->set("long","这是一颗普通的鸡蛋，你可以试着孵化它。(fu)\n看起来这颗鸡蛋已经孵化了"+chinese_number(query("time")/10+1)+"成了。\n");
				if(inv[i]->query("time") >= 100)
				{
					message_vision(HIY"一只小鸡破壳而出啦！\n"NOR,this_player());
					chick = new(__DIR__"xiaoji");
					if(environment(this_object())->isroom() != 1)
					{
						chick->move(environment(environment(this_object())));
					}
					else
					{
						chick->move(environment(this_object()));
					}
					destruct(inv[i]);
					add("eggs",-1);
				}				
			}
		}
	}
	this_player()->add_busy(10+random(10));
	save();
	return 1;
}