// tie_xiang.c
inherit ITEM;

private int lock = 1;
void create()
{
        set_name("铁箱", ({ "tie xiang" , "xiang"}) );
        set_weight(50000);
        set_max_encumbrance(8000000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "只");
		set("long", "这是一只铁皮箱，中间挂着一把大锁(lock)，两边贴着封条，封条上写着：洪百万封。\n");
		set("value", 1);
		set("no_get",1);
		set("no_drop",1);
        }
}

int is_container() { return 1; }

void init()
{
	add_action("do_pi",({"pi","za"}));
	add_action("do_get","get");
	add_action("do_put","put");
}

int do_get(string arg)
{
	string what;
	if(!arg) return 0;
	if(sscanf(arg, "%s from %s", arg, what)==2)
	{
		if(id(what))
		{
			if(lock)
			{
			write("铁箱被锁上了。\n");
			return 1;
			}
			else if(arg == "all" || arg == "qsword")
			{
			write("你打开铁箱，");
			return 0;
			}
		return 0;
		}
	return 0;
	}
	else return 0;
}

int do_put(string arg)
{
	string what;
	if(!arg) return 0;
	if(sscanf(arg, "%s in %s", arg, what)==2)
	{
		if(id(what))
		{
			if(lock)
			{
			write("铁箱被锁上了。\n");
			return 1;
			}
		return 0;
		}
	return 0;
	}
	else return 0;
}

int do_pi(string arg)
{
	object weapon,me = this_player();
	if(!arg || arg == "")
		return notify_fail("你要砸什么？\n");
	if(arg != "lock" && arg != "大锁" && arg != "锁")
		return notify_fail("你要砸什么？\n");
	if(!lock)
		return notify_fail("大锁已经被砸开了。\n");

	if(!objectp(weapon = me->query_temp("weapon")))
		return notify_fail("空手要砸开大锁恐怕是不行。\n");

	message_vision("$N挥动手中的"+weapon->query("name")+"向大锁砸去。\n",me);
	if(me->query("force") < 100 ){
	message_vision("结果大锁纹丝没动。\n",me);
	return 1;
	}
	message_vision("大锁“哐啷”一声被砸开了。\n",me);
	lock = 0;
	me->add("force",-100);
	set("long", "这是一只铁皮箱，上面的锁已经不知被谁砸开了。\n");
	return 1;
}
