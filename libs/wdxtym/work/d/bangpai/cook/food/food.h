inherit COMBINED_ITEM;

int add_buff(object who);
void remove_buff(object who);

void create_food(mapping food_info)
{
	set_name(food_info["name"], ({food_info["id"]}));
	set("long", food_info["name"] + "。\n");
	set("base_unit", food_info["unit"]);
	set("base_value", 1);
	set("base_weight", 1);
	set("need", food_info["need"]);
	set("action_list", ([
		"吃" : "eat " + file_name(this_object()),
		]));
	set("time", food_info["time"]);
	
	set("food", 1);
	set_amount(1);
	setup();
}

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}


void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object who = this_player();
	
	if (arg != file_name(this_object()))
		return 0;
	if (who->query_temp("eat_food"))
	{
		write("你吃的食物buff时间没过，无法再吃新的食物。\n");
		return 1;
	}
	if (query("no_buff"))
	{
        write("你吃下了" + query("name") + "。\n");
        add_amount(-1);
        return 1;
	}
	
	if (add_buff(who))
	{
		who->food_call_out((: call_other, __FILE__, "remove_buff", who :), this_object()->query("time"));
	}
	
	//write("你吃下了一盘" + query("name") + "。\n");
	add_amount(-1);
	return 1;
}