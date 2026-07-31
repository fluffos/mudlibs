inherit ROOM;

void create()
{
	set("short", "营地");
	set("long", @LONG
为剿匪所搭建的临时营地，通向各个城市。
LONG);
	set("action_list", ([
		"城市目录" : "goto_city",
		"副本指令" : "jiaofei",
		]));
	set("item_desc", ([
		"副本说明" : "击杀匪徒时，全队成员必须和匪徒在同一房间\n"
					  "成员离开副本会导致副本结束\n"
					  "使用追杀令(商城购买)可以获得匪徒位置\n"
					  "每十环获得一个物品奖励（仅队长）\n"
					  "每日五十环后不再获得修为潜能\n"
					  "匪徒会自动叫杀经过的玩家\n",
		"火堆" : "啊！熊熊的烈火啊，把一切焚烧殆尽。\n",
		]));
		
	setup();
}

void init()
{
	add_action("do_fuben_go", "fuben_go");
	add_action("do_goto_city", "goto_city");
}

int do_goto_city()
{
	int i;
	string area, str = "";
	mapping city;
	
	city = this_object()->query("fuben_exits");
	str += "你想去哪里：\n" + ZJOBACTS2 + ZJMENUF(2,2,9,30);
	
	for(i = 0; i < sizeof(city); i++)
	{
		sscanf(city[sprintf("%d", i)], "/d/%s/%*s",area);
		str += MAP_D->query_map_short(area) + ":fuben_go " + i + ZJSEP;
	}
	
	tell_object(this_player(), ZJOBLONG + str +"\n");
	
	return 1;
}
int do_fuben_go(string arg)
{
	mapping exits;
	
	exits = this_object()->query("fuben_exits");
	
	if (!arg)
		return notify_fail("你想去哪里？\n");
	
	if (exits[arg])
	{
		this_player()->move(exits[arg]);
		tell_object(this_player(), "你来到了" + exits[arg]->query("short") + "\n");
	}
	else
		return notify_fail("你想去哪里？\n");
		
	return 1;
}