// ping.c 平一指

inherit NPC;
inherit F_DEALER;

string ask_job();
string ask_fail();

string s_skill;
string ask_special_skill();

void create()
{
	set_name("平一指", ({ "ping yizhi", "ping", "yizhi" }));
	set("title", "药铺老板");
	set("gender", "男性");
     set("start_room","/d/city/yaopu");
	set("long", "他就是医术高超的「杀人神医」平一指。可是他性格古怪，不是什么人都医的。\n");
	set("age", 65);

	set("int", 30);
	
	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("shen_type", 1);

	set("combat_exp", 500000);
	set("attitude", "heroism");

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 60);
	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/damage", 50);

	set("vendor_goods", ({
	}));
		// 特别技能指导能力
		s_skill = "chinese-medicine";
	set("inquiry",([
		"工作":(:ask_job:),
		"失败":(:ask_fail:),
                s_skill       : (: ask_special_skill :),
		]));
	setup();
	add_money("gold", 1);
}

void init()
{
//add_action("do_buy", "buy");
}


string ask_special_skill()
{
	object user;
	int cur_lvl;
	
	user = this_player();
	if (!user->query_temp("mark/ok_"+s_skill))
	{
		// max lvl == 20
		if ((cur_lvl = SPECIAL_D->query_level(user, s_skill)) >= 20 )
			return "你的技能已经太高，老身已经无法指点你了。\n";
		
		// lvl <= user_lvl /2
		if (cur_lvl*2 +2 > (int)user->query("level"))
			return "受你的等级限制，我无法继续指点你"+to_chinese(s_skill);
		
		if (user->query("level_used")>= user->query("level"))
			return "你的特别潜能点数已经用完了。";
		
		if (user->query("nation")!= "天竺部族")
			return user->query("nation")+"怕是难以修习"+to_chinese(s_skill)+"。";
			
		if (!SPECIAL_D->query_level(user, "master-int"))
			return "你先要修习"+to_chinese("master-int")+"(master-int)才能修练"+to_chinese(s_skill)+"。";
		
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
			message_vision(query("name")+"在$N耳边轻声说了几句草药的诀窍。\n", user);
			tell_object(user, "你的"+to_chinese(s_skill)+"("+s_skill+")进步了！\n");
			tell_object(user, "你的疾病治疗术有所提高。\n");
			return "我每救一个人，就要杀一个人！";
		}
	}
	return "什么？";
}


string ask_job()
{
	object ppl=this_player(),yaofang;
	 if(ppl->query("combat_exp")>2000)
        {
            return "在我这里配药太埋没您拉，您还是去干点别的吧。\n";
        }
 
	if (ppl->query_temp("peiyao/in_job"))
		return "你上次的工作还没有完成！";
	else
	{
		yaofang=new(__DIR__"obj/yaofang");
		yaofang->move(ppl);
		ppl->set_temp("peiyao/in_job",1);
		ppl->set_temp("peiyao/ok",0);
		return "我们现在正好缺少一种药，这是药方，你去配吧";
	}
}

string ask_fail()
{
	object ppl=this_player();
	if (!ppl->query_temp("peiyao/in_job"))
			return "我没有让你配药呀？";
	if (ppl->query_temp("peiyao/ok"))
		return "你不是已经把药配好了吗？";
	ppl->set_temp("peiyao/in_job",0);
    write("平一指叹了口气，说道：这点小事都干不好，还想在江湖上混？\n");
	return "你走吧，我看见你就来气";
}

