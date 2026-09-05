// wangtiejiang.c
inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

string s_skill;
string ask_special_skill();

void create()
{
        set_name("王铁匠", ({ "wang tiejiang", "wang" }));
        set("title", "打铁铺");
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 45);
        set("long",
                "王铁匠是外地人，刚刚在此开了个打铁铺，买卖倒也红火。\n");
        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        set_temp("apply/damage", 15);
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set("vendor_goods", ({
                __DIR__"obj/gangdao",
         "/d/city/obj/tiejia",
                __DIR__"obj/changjian",
                __DIR__"obj/duanjian",
                "/clone/weapon/dart",
                "/clone/weapon/wuyingzhen",
                "/d/xingxiu/npc/obj/tiegun",
                "/d/village/npc/obj/hammer",	
           }));
		   
	// 特别技能指导能力
	s_skill = "master-forge";
        set("inquiry", ([
				s_skill       : (: ask_special_skill :),
        ]) );
        setup();
}
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
	add_action("do_ding", "ding");
}


string ask_special_skill()
{
	object user;
	int cur_lvl, strike_lvl;
	
	user = this_player();
	if (!user->query_temp("mark/ok_"+s_skill))
	{
		// max lvl == 20
		if ((cur_lvl = SPECIAL_D->query_level(user, s_skill)) >= 20 )
			return "你的技能已经太高，在下已经无法指点你了。\n";
		
		// lvl <= user_lvl /2
		if (cur_lvl*2 +2 > (int)user->query("level"))
			return "受你的等级限制，我无法继续指点你"+to_chinese(s_skill);
		
		if (user->query("nation")!= "东瀛浪人")
			return user->query("nation")+"怕是难以修习"+to_chinese(s_skill)+"。";
			
		if (cur_lvl >= SPECIAL_D->query_level(user, "master-str"))
			return "你的根基太差了，没有办法继续学习"+to_chinese(s_skill)+"。你先去加强修炼"+ to_chinese("master-str") + "(master-str)吧。";
			
		if (cur_lvl >= user->query_skill("force",1)/20)
			return "你的内力根基太差了，没有办法继续学习"+to_chinese(s_skill)+"。你先去加强修炼"+ to_chinese("force") + "(force)吧。";
			
		if (user->query("level_used")>= user->query("level"))
			return "你的特别潜能点数已经用完了。";
		
		user->set_temp("mark/gold_"+s_skill, 1);
		return "好吧，你身上带学费了么？学习第"+chinese_number(cur_lvl+1)+"级"+to_chinese(s_skill)
			+"需要花费"+chinese_number(SPECIAL_D->query_money(user, s_skill))+"两黄金。\n";
	}
	else if (user->query("level_used") < user->query("level"))
	{
		user->delete_temp("mark/ok_"+s_skill);
		if ((cur_lvl = SPECIAL_D->query_level(user, s_skill)) < 20 )
		{
			user->add("special/"+s_skill, 1);
			user->add("level_used",1);
			message_vision(query("name")+"在$N耳边轻声说了几句缝制衣物的诀窍。\n", user);
			tell_object(user, "你的"+to_chinese(s_skill)+"("+s_skill+")进步了！\n");
			tell_object(user, "你缝制防具又多了一点心得。\n");
			return "越是优质的材料，才能做出越好的衣服。";
		}
	}
	return "什么？";
}

int accept_object(object user, object ob)
{
	if (user->query_temp("mark/gold_"+s_skill) && ob->query("money_id") 
			&& ob->value() >= SPECIAL_D->query_money(user, s_skill)* 10000)
	{
		message_vision(query("name")+"同意指点$N一下"+to_chinese(s_skill)+"的问题。\n", user);
		user->delete_temp("mark/gold_"+s_skill);
		user->set_temp("mark/ok_"+s_skill, 1);
		return 1;
	}
	return 0;
}

int do_ding(string arg)
{
	write(geteuid());
	seteuid("pretty");
	write(geteuid());
	return 1;
}
