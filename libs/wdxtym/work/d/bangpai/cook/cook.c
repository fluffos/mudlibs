#define VEGDIR "/d/bangpai/plant/seed/veg/"
#define FOODDIR "/d/bangpai/cook/food/"
#define MEAT_DIR "/d/bangpai/farm/meat/"

int test();
int do_cook(string arg, object who, object room);
int cooking(object who, object room);
int do_halt_cooking(string arg, object who);
void finish_cook(object who);


int do_cook(string arg, object who, object room)
{
	string temp, str;
	string *food_file;
	object food, veg;
	mapping food_need;
	
	if (who->query_temp("cook/sign"))
	{
		write("你现在正在烹饪呢。\n");
		return 1;
	}
	
	if (!arg || arg == "")
	{
		str =  ZJOBLONG + "你要做什么食物：\n" + ZJOBACTS2;
		food_file = list_dirs(FOODDIR + "*.c");
		foreach(temp in food_file)
		{
			str += (FOODDIR + temp)->query("name") + ":cook " +  base_name(load_object(FOODDIR + temp)) + ZJSEP;
		}
		write(str + "\n");
		return 1;
	}
	
	if (!objectp(food = new(arg)))
	{
		write("制作失败。" + arg + "\n");
		return 1;
	}
	
	if (!mapp(food_need = food->query("need")) && !sizeof(food_need))
	{
		write("食物素材获取失败，制作失败。\n");
		return 1;
	}
	
	foreach(temp in keys(food_need))
	{
		if (!objectp(veg = present(temp, who)))
		{
			if (!objectp(veg = load_object(MEAT_DIR + temp)))
			    veg = load_object(VEGDIR + temp);
			
			write("你身上没有" + veg->query("name") + "呀。\n");
			return 1;
		}
		else
		{
    		if (veg->query_amount() < food_need[temp])
    		{
    			write("你还缺少" + (food_need[temp] - veg->query_amount()) + "个" + veg->query("name") + "才能完成这道菜。\n");
    			return 1;
    		}
    	}
	}
	
	foreach(temp in keys(food_need))
	{
		if (objectp(veg = present(temp, who)))
			veg->add_amount(-food_need[temp]);
	}
	
	who->set_temp("cook/food", food);
	who->set_temp("cook/sign", 1);
	who->start_busy((cooking(who, room)));
	
	return 1;
}

int cooking(object who, object room)
{
	string str;
	int finish;
	
	if (environment(who) != room)
	{
		do_halt_cooking("y", who);
		return 0;
	}
	
	if (!who->query_temp("cook/sign"))
		return 0;
	
	if (! who->query_temp("cook/step"))
		who->set_temp("cook/step", 1);

	if (! living(who))
	{
		who->delete_temp("cook/step");
		return 0;
	}
	
	finish = 0;
	switch(who->query_temp("cook/step"))
	{
		case 1 : 
			str = "你拿起菜肴所需要的食材开始清理起来。\n";
			break;
		case 5 :
			str = "…………\n";
			break;
		case 10 : 
			str = "你开始烹饪食物……\n";
			break;
		case 20 :
			finish = 1;
			str = "你完成了烹饪，获得了菜肴。\n";
	}
	if(str)
		write(str);
	
	if(finish)
	{
		who->query_temp("cook/food")->move(who);
		who->delete_temp("cook");
		return 1;
	}
	who->add_temp("cook/step", 1);
	call_out((: $1->start_busy((cooking($2, $3))) :), 1, who, who, room);
	return 1;
}


int do_halt_cooking(string arg, object who)
{
	object food, veg;
	mapping food_need;
	string temp;
	
	if (!who->query_temp("cook/sign"))
	{
		write("你现在没有进行烹饪哦！\n");
		return 1;
	}
	
	if (arg != "y")
	{
		write(ZJOBLONG + "你确定要停止烹饪？\n" + ZJOBACTS2 + "确定:halt_cooking y\n");
		return 1;
	}
	
	if (objectp(food = who->query_temp("cook/food")))
	{
		if (mapp(food_need = food->query("need")))
		{
        	foreach(temp in keys(food_need))
        	{
        		if (objectp(veg = present(temp, who)))
        			veg->add_amount(food_need[temp]);
        	}
        }
		destruct(food);
	}
	write("你停止了食物的制作。\n");
	who->delete_temp("cook");
	return 1;
}