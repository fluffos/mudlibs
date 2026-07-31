int kaitong(object who, string arg)
{
	if(arg != "y")
	{
		write(ZJOBLONG + "你确定要开通菜园功能吗？（需要200金子）\n" + ZJOBACTS2 + "确定:kaitong y\n");
		return 1;
	}
	
	if (!PLANTVEG_D->query_kaitong(who))
	{
		write("你已经开通菜园功能了。\n");
		return 1;
	}
	
	if(!MONEY_D->player_pay(who, 2000000))
	{
		write("你的钱没那么多了！\n");
		return 1;
	}
	
	if(!PLANTVEG_D->create_player_caidi(who))
	{
	    write("你成功开通了菜园功能。\n");
	    return 1;
	}
	return 1;
}

int kuojian(object who, string arg)
{
	int count;
	
	if(arg != "y")
	{
		write(ZJOBLONG + "你确定要扩建菜地吗？（需要200金子）\n" + ZJOBACTS2 + "确定:kuojian y\n");
		return 1;
	}
	
	if ((count = pow(who->query("combat_exp") * 10, 0.3333333)/100 + 4) <= (PLANTVEG_D->query_caidi_count(who)))
	{
		write("你当前只能拥有" + count + "块地。\n");
		return 1;
	}
	
	if(!MONEY_D->player_pay(who, 2000000))
	{
		write("你的钱没那么多了！\n");
		return 1;
	}
	
	if(!PLANTVEG_D->add_player_caidi(who))
	{
		write("你目前还没开通菜园功能。\n");
		return 1;
	}
	
	write("你扩建了你的土地。\n");
	return 1;
}


int look_caidi(object who, string arg)
{
	mapping caidi;
	string str;
	int i;
	
	if(sizeof(caidi = PLANTVEG_D->query_player_caidi(who)))
	{
		str = "你目前的菜地情况如下：\n" + ZJOBACTS2+ZJMENUF(2,2,10,25);
		for(i = 0; i < sizeof(caidi); i++)
		{
			if(caidi[i] != "none")
			{
				str += caidi[i]["mature_name"] + ":lookveg " + i + ZJSEP;
			}
			else
			{
				str += "种植:plantveg " + i + " " + ZJSEP;
			}
		}
		
		write(ZJOBLONG + str + "\n");
	}
	else
		write(ZJOBLONG + "你还没有菜地。\n");
	return 1;
}

int plantveg(object who, string arg)
{
	object seed;
	object *seeds;
	string str;
	int num;
	
	if(sscanf(arg,"%d %s", num, seed) != 2)
	{
		if(!sizeof(seeds = filter_array(all_inventory(who), (: ($1)->query("seed") :))))
		{
			write("你的身上没有种子。\n");
			return 1;
		}
		
		str = "你要种植什么种子：\n" + ZJOBACTS2+ZJMENUF(2,2,10,25);
		foreach(seed in seeds)
		{
			str += seed->query("name") + ":plantveg " + arg + " " + file_name(seed) + ZJSEP;
		}
		write(ZJOBLONG + str + "\n");
		return 1;
	}
	
	if(PLANTVEG_D->add_vegetable(who, seed, num))
	{
		seed->add_amount(-1);
		write("种植成功。\n");
	}
	else
		write("种植失败。\n");
	return 1;
}

int lookveg(object who, string arg)
{
	mapping veg;
	int num;
	string str = "";
	
	if(!sscanf(arg, "%d", num))
		return ;
	
	veg = PLANTVEG_D->query_vegetable(who, num);
	if (veg["time"] < time())
	{
		str += "这是一棵成熟的" + veg["mature_name"] + "。\n"  + ZJOBACTS2+ZJMENUF(2,2,10,25);
		str += "采收:shouveg " + num;
	}
	else
	{
		str += "这是一棵未成熟的" + veg["mature_name"] + "(" + CHINESE_D->chinese_time(veg["time"] - time()) + "后成熟)。\n" ZJOBACTS2+ZJMENUF(2,2,10,25);
		str += "铲掉:chanveg " + num;
	}
	
	write(ZJOBLONG + str + "\n");
	return 1;
}

int shouveg(object who, string arg)
{
	object vegetable;
	int num;
	mapping veg;
	
	if(!sscanf(arg, "%d", num))
		return 1;
		
	veg = PLANTVEG_D->query_vegetable(who, num);
	if(veg["time"] > time())
	{
		write("这棵" + veg["mature_name"] + "未成熟！\n");
		return 1;
	}
	vegetable = new(veg["mature"]);
	vegetable->move(who);
	PLANTVEG_D->delete_vegetable(who, num);
	
	write("你收获了一棵" + veg["mature_name"] + "。\n");
	return 1;
}

int chanveg(object who, string arg)
{
	int num;
	mapping veg;
	
	if(!sscanf(arg, "%d", num))
		return 1;
	else if (sscanf(arg, "%d %s", num, arg) != 2 && arg != "y")
	{
		write(ZJOBLONG + "你确定要铲除吗？\n" + ZJOBACTS2 + "确定:chanveg " + num + " " + "y\n");
		return 1;
	}
	
	veg = PLANTVEG_D->query_vegetable(who, num);
	if(veg["time"] < time())
	{
		write("这棵" + veg["mature_name"] + "已经成熟了，快采收吧！\n");
		return 1;
	}
	PLANTVEG_D->delete_vegetable(who, num);
	write("你拔掉了一棵未成熟的" + veg["mature_name"] + "。\n");
	return 1;
}