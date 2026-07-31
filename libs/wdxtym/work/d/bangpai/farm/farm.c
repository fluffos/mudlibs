#define ANIMAL_DIR "/d/bangpai/farm/animal/"
#define MEAT_DIR "/d/bangpai/farm/meat/"

mapping animals = ([    //数值单位为金子
    "pig" : 10,
    "sheep" : 20,
]);


void kaitong(object who, string arg)    //开通牧场功能
{
    if (FARM_D->query_player_farmd(who))
    {
        write("你已经开通牧场功能了。\n");
        return ;
    }
    
    if (!arg || arg == "")
    {
        write(ZJOBLONG + "你确定要花费200金子开通牧场功能吗？\n" + ZJOBACTS2 + "确定:kaitong y\n");
        return ;
    }
    
    if (arg != "y")
    {
        write("格式错误，请重新输入。\n");
        return ;
    }
    
    if (!MONEY_D->player_pay(who, 2000000))
    {
        write("你的钱不够了。\n");
        return ;
    }
    
    if (FARM_D->set_player_farmd(who) && FARM_D->add_animal_amount(who))
    {
        write("你成功开通牧场功能。\n");
        return ;
    }
    else
    {
        write("开通牧场功能失败，请联系管理员处理。\n");
        return ;
    }
}

void kuojian(object who, string arg)    //扩建
{
    int count;
    
    if (!FARM_D->query_player_farmd(who))
    {
        write("你还没有开通牧场功能。\n");
        return ;
    }
    
    if (!arg || arg == "")
    {
        write(ZJOBLONG + "你确定要花费200金子扩建牧场吗？\n" + ZJOBACTS2 + "确定:kuojian y\n");
        return ;
    }
    
    if (arg != "y")
    {
        write("格式错误，请重新输入。\n");
        return ;
    }
    
	if ((count = pow(who->query("combat_exp") * 10, 0.3333333)/100 + 4) <= (FARM_D->get_animal_amount(who)))
	{
		write("你当前最多只能养" + count + "只动物。\n");
		return ;
	}
	
    if (!MONEY_D->player_pay(who, 2000000))
    {
        write("你的钱不够了。\n");
        return ;
    }
    
    if (FARM_D->add_animal_amount(who))
    {
        write("你成功扩建农场。\n");
        return ;
    }
    else
    {
        write("扩建失败，请联系管理员处理。\n");
        return ;
    }
}

void buy_animal(object who, string arg)    //购买动物
{
    string str = "";
    string temp, sign;
    object animal;
    int i;
    
    if (!FARM_D->query_player_farmd(who))
    {
        write("你还没有开通牧场功能。\n");
        return ;
    }
    
    if (!arg || arg == "")
    {
        foreach(temp in keys(animals))
        {
            str += (ANIMAL_DIR + temp)->query("name") + "  " + animals[temp] + "金:buy_animal " + temp + ZJSEP;
        }
        
        write(ZJOBLONG + "你要买什么动物？\n" + ZJOBACTS2 + str + "\n");
        return ;
    }
    
    if (sscanf(arg, "%s %s", arg, sign) != 2)
    {
        write(ZJOBLONG + "你要购买花费" + animals[arg] + "金子购买" + (ANIMAL_DIR + arg)->query("name") + "吗？\n" + ZJOBACTS2 + "确定:buy_animal " + arg + " y\n");
        return ;
    }
    
    if (sign != "y")
    {
        write("格式错误，请重新输入。\n");
        return ;
    }
    
    if (FARM_D->get_animal_amount(who) <= sizeof(FARM_D->get_animal(who)))
    {
        write("你目前的牧场已经满了。\n");
        return ;
    }
    
    if (!MONEY_D->player_pay(who, animals[arg] * 10000))
    {
        write("你的钱不够了。\n");
        return ;
    }
    
    if (i = FARM_D->add_animal(who, arg))
    {
        write("你购买了一只" + (ANIMAL_DIR + arg)->query("name") + "。\n");
        animal = new(ANIMAL_DIR + arg);
        animal->set("animal", i - 1);
        animal->set("mature_time", time() + animal->query("need_time"));
        //
        //animal->set_name(animal->query("name") + animal->query("animal"), ({animal->query("id")}));
        //
        animal->move(environment(who));
        return ;
    }
    else
    {
        write("错误，请联系管理员处理。\n");
        return ;
    }
    
    return ;
}

void slaughter_animal(object who, string arg)    //杀掉动物
{
    string sign;
    string animal_name;
    int meat_amount;
    object meat;
    
    if (sscanf(arg, "%s %s", arg, sign) != 2)
    {
        write(ZJOBLONG + "你确定要杀掉" + arg->query("name") + "吗？\n" + ZJOBACTS2 + "确定:slaughter_animal " + arg + " y\n");
        return ;
    }
    
    if (sign != "y")
    {
        write("格式错误，请重新输入。\n");
        return ;
    }
    
    if (!find_object(arg) || !arg->query("is_animal") || environment(find_object(arg)) != environment(who))
    {
        write("不存在此对象或对象不为动物或该对象不在你的牧场。\n");
        return ;
    }
    
    if (find_object(arg)->query("mature_time") > time())
    {
        write("还未成熟，不能屠宰。\n");
        return ;
    }
    
    if (FARM_D->delete_animal(who, arg->query("animal")))
    {
        animal_name = arg->query("name");
        meat_amount = arg->query("meat");
        meat = new(MEAT_DIR + arg->query("meat_name"));    //修改
        meat->set_amount(meat_amount);
        meat->move(who);
        destruct(find_object(arg));
        write("你杀掉" + animal_name + "获得" + meat_amount + animal_name + "肉。\n");
        return ;
    }
    else
    {
        write("错误，请联系管理员处理。\n");
        return ;
    }
}

void sell_animal(object who, string arg)    //卖掉动物
{
    string sign;
    string animal_name;
    int gold_amount;
    object money_gold;
    
    if (sscanf(arg, "%s %s", arg, sign) != 2)
    {
        write(ZJOBLONG + "你确定要卖掉" + arg->query("name") + "吗？\n" + ZJOBACTS2 + "确定:sell_animal " + arg + " y\n");
        return ;
    }
    
    if (sign != "y")
    {
        write("格式错误，请重新输入。\n");
        return ;
    }
    
    if (!find_object(arg) || !arg->query("is_animal") || environment(find_object(arg)) != environment(who))
    {
        write("不存在此对象或对象不为动物或该对象不在你的牧场。\n");
        return ;
    }
    
    if (FARM_D->delete_animal(who, arg->query("animal")))
    {
        animal_name = arg->query("name");
        gold_amount = animals[arg->query("id")] * 7 / 10;
        money_gold = new("/clone/money/gold");
        money_gold->set_amount(gold_amount);
        money_gold->move(who);
        destruct(find_object(arg));
        write("你卖掉了" + animal_name + "获得了" + gold_amount + "金子。\n");
        return ;
    }
    else
    {
        write("错误，请联系管理员处理。\n");
        return ;
    }
}

void init_muchang(object who, object room)    //初始化牧场
{
    mapping animals;
    int i;
    object ob;
    
    if (sizeof(animals = FARM_D->get_animal(who)))
    {
        for(i = 0; i < sizeof(animals); i++)
        {
            ob = new(ANIMAL_DIR + animals[i]["name"]);
            ob->set("animal", i);
            ob->set("mature_time", animals[i]["time"]);
            ob->move(room);
        }
    }
}

void look(object who, object ob)    //look
{
    string str = "";
    
    str += ob->short();
    str += "\n一一一一一一一一一一一一一一一一一一一一一一一\n";
    str += ob->long() + "(" + (((ob->query("mature_time") - time()) > 1)?CHINESE_D->chinese_time(ob->query("mature_time") - time()) + "后成熟" : "已成熟") + ")\n";
	str = replace_string(str,"\n",ZJBR);
    if (str[(strlen(str)-4)..(strlen(str)-1)]=="$br#")
        str = str[0..(strlen(str)-5)];
        
    str +=  "\n" + ZJOBACTS2 + "残忍杀害:slaughter_animal " + ob + ZJSEP + "出售:sell_animal " + ob + "\n";
    write(ZJOBLONG + str + "\n");
}