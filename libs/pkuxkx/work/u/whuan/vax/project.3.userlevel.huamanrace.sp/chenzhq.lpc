// waiter.c

inherit NPC;
inherit F_DEALER;

string s_skill;
string ask_special_skill();

void create()
{
	set_name("陈震骐", ({ "chen zhenqi","chen"}) );
	set("gender", "男性" );
	set("age", 32);
     set("start_room","/d/city/yidian");
	set("long",
		"这是扬州城有名的裁缝，老扬州没有不知道他的，每到逢年过节，家里\n"
                "办喜事，他这的生意就好的不得了.\n");
	set("combat_exp", 10000);
	set("attitude", "friendly");
	set("rank_info/respect", "老板");
      	set("vendor_goods", ({
		__DIR__"obj/zhja",
		__DIR__"obj/zlq",
		__DIR__"obj/dpdc",
               __DIR__"obj/xscp",
                __DIR__"obj/xhxa",
            __DIR__"obj/qbcs",
            }));

	// 特别技能指导能力
	s_skill = "master-clothing";
        set("inquiry", ([
				s_skill       : (: ask_special_skill :),
        ]) );
        
	setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	object ob;

	::init();
    add_action("do_list","list");
    add_action("do_buy","buy");
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
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
		
		if (user->query("nation")!= "游牧民族")
			return user->query("nation")+"怕是难以修习"+to_chinese(s_skill)+"。";
			
		if (cur_lvl >= SPECIAL_D->query_level(user, "master-int"))
			return "你的根基太差了，没有办法继续学习"+to_chinese(s_skill)+"。你先去加强修炼"+ to_chinese("master-int") + "(master-int)吧。";
			
		if (cur_lvl >= user->query_skill("literate",1)/20)
			return "你的智慧根基太差了，没有办法继续学习"+to_chinese(s_skill)+"。你先去加强修炼"+ to_chinese("literate") + "(literate)吧。";
			
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



void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
        if( !this_object()->visible(ob)) return;
        if (ob->query("gender")=="女性")
           {
            command("xixi "+ ob->query("id"));
            command("bow");
            command("say 这位姑娘，本店有上好的衣服，您这么漂亮也不来几套！");
           }
        else if (ob->query("gender")=="无性")
           {
            command("hi "+ ob->query("id"));
            command("xixi");
            command("say 这位公公，本店有各式男女服装，您也不来几套！");
           }
        else
           {
            command("haha"); 
            command("hi " +ob->query("id"));
            command("say 这位大爷，您是自己买衣服，还是要送给心上人呢？");
           }
           
}

