inherit NPC;
inherit F_SAVE;

string ask_buchang();

void create()
{
    set_name("五一使者", ({"wuyi shizhe"}));
    set("long", "五一使者。\n");
    set("gender", "女性");
    set("age",17);
    set("combat_exp", 1);
    set("create_time", (time()/86400 + 1) * 86400);
    
    set("inquiry", ([
            "【五一活动】" : (: ask_buchang :),
        ]));
    
    setup();
}

string ask_buchang()
{
	object gift, who = this_player();
	string str = "";
	
	if (who->query("birthday") > query("create_time"))
	{
		return ("只有在" + CHINESE_D->chinese_date(query("create_time"), 1) + "之前创建的角色才能领取。\n");
	}
	
	if (who->query("wuyi_lingqu") != 8)
	{
		if ((time() - who->query("birthday")) / 360 < 2)
		{
			return "你注册未满两小时，无法领取。";
		}

		gift = new("/clone/baiyi/tencard");
		//gift->set_amount(2);
		gift->move(who);
		who->set("wuyi_lingqu", 8);
		log_file("buchang_shilian", ctime(time()) + who->name() + "领取了五一 十连抽卡片。\n");
		return "你获得了一张十连抽卡片。\n";
	}

	
	// if (who->query("buchang_lingqu") != 4)
	// {
	// 	if ((time() - who->query("birthday")) / 360 < 2)
	// 	{
	// 		return "你注册未满两小时，无法领取。";
	// 	}
		
	// 	if (query(who->query("id")))
	// 	{
	// 		return "你已经领取过补偿了。\n";
	// 	}
		
	// 	str = "";
	// 	who->set("buchang_lingqu", 4);
	//     if (objectp(gift = new("/clone/gift/putao1")))
	//     {
	// 	    gift->set_amount(10);
	// 	    str += "恭喜你你获得了" + gift->short();
	// 		log_file("buchang_shilian", ctime(time()) + who->name() + who->query("id") + "领取了神奇葡萄。\n");
	// 		gift->move(who);
	// 	}
	// 	if (objectp(gift = new("/clone/baiyi/tencard")))
	// 	{
	// 		log_file("buchang_shilian", ctime(time()) + who->name() + "领取了十连抽卡片。\n");
	// 		gift->move(who);
	// 		str += "你获得了一张十连抽卡片。";
	// 	}
	// 	if (objectp(gift = new("/clone/gift/tianxiang1")))
	// 	{
	// 		log_file("buchang_shilian", ctime(time()) + who->name() + "领取了天香玉露。\n");
	// 		gift->set_amount(5);
	// 		gift->move(who);
	// 		str += "你获得了五个天香玉露";
	// 	}

	// 	set(who->query("id"), 1);
	// }
	else
		return "你已经领取过奖励了，无法再次领取了哦。";

	return str;
}


void die()
{
	object ob, me, who;
	
	me = this_object();
	who = me->query_last_damage_from();
	ob = new(base_name(me));
	ob->set("create_time", query("create_time"));
	ob->move(environment(me));
	tell_object(who, ZJOBLONG + "小千：你这个恶魔，你会受到诅咒的！你再杀会死的！\n");
	log_file("kill_qian", ctime(time()) + "   " + who->name() + "\n");
	
	::die();
}

void init()
{
    add_action("disable", ({ "kill", "hit", "fuhuo", "touxi", "fight", "steal"}));
}

int disable(string arg)
{
    object who = this_player();
    
    if (arg != "qian")
        return 0;
    
    tell_object(who, "小千一脚踢向你，你倒在地上动弹不得。\n");
    who->start_busy(180);

    return 1;
}

int accept_ansuan(object who)
{
    tell_object(who, "你想暗算小千……\n小千：哼，还想暗算我？乖乖在原地罚站吧！\n");
    who->start_busy(300);
    return 0;
}

void fight_ob(object ob)
{
	::fight_ob(ob);
    tell_object(ob, "小千一脚踢向你，你倒在地上动弹不得。\n");
    ob->start_busy(180);
    
}

int accept_fight(object who)
{
	command("say 没兴趣。");
	return 0;
}

void receive_damage(string type, int n)
{
	return;
}

void receive_wound(string type, int n)
{
	return;
}