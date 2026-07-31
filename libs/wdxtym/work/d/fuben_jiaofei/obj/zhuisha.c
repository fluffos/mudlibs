inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void create()
{
	set_name(HIW"追杀令"NOR, ({"zhuisha ling", "zhuisha"}));
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("base_unit", "个");
		set("base_weight", 1);
		set("base_value", 10000);
		set("long","这是追杀令，使用后能够获得"NOR"当前匪徒npc的精确位置！\n");
	}
	set_amount(1);
	setup();
}

void init()
{
    if (environment()==this_player())
    	add_action("on_used","use");
}

int on_used(string arg)
{
	int i = 0;
	object who, temp;
	object *npc_obj;
	string area;
	
	if (arg != "zhuisha ling")
		return notify_fail("你要使用什么？\n");
	
	who = this_player();
	if (!(environment(who)->query("is_fuben")))
	{
		tell_object(who, "追杀令只能在剿匪副本中使用。\n");
		return 1;
	}
	
	npc_obj = (who->query_temp("fb_mem"))->query("npc_obj");
	foreach(temp in npc_obj)
	{
		if(temp && objectp(temp) && environment(temp))
		{
			sscanf(base_name(environment(temp)),"/d/%s/%*s",area);
			message("shout", ZJOBLONG + "(" + who->name() + "使用了追杀令) 匪徒所在的地点为" + MAP_D->query_map_short(area) + "的" + environment(temp)->query("short") + "。\n", (who->query_temp("fb_mem"))->query("team"));
			message("shout", "(" + who->name() + "使用了追杀令) 匪徒所在的地点为" + MAP_D->query_map_short(area) + "的" + environment(temp)->query("short") + "。\n", (who->query_temp("fb_mem"))->query("team"));
			break;
		}
		i += 1;
		if(i == sizeof(npc_obj))
			tell_object(who, "无法查询到匪徒所在，可能已经被全部杀死。\n");
	}
	add_amount(-1);
	return 1;
}