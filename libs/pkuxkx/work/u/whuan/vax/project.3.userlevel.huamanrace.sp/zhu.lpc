// zhu.c 朱熹
// CLEANSWORD 1996/2/2

inherit NPC;
inherit F_DEALER;
inherit F_MAILQUEST;

string s_skill;
string ask_special_skill();
void create()
{
	set_name("朱熹", ({ "zhu xi", "zhu" }));
	set("long", "朱先生被称为当世第一大文学家，肚子里的墨水比海还要深。\n");
	set("gender", "男性");
	set("age", 65);
     set("start_room","/d/city/shuyuan");

	set_skill("literate", 300);

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 400000);
	set("shen_type", 1);
set("vendor_goods",({
__DIR__"obj/shu2",
"/d/city/obj/baodian",
}));
	// 特别技能指导能力
	s_skill = "master-int";
	set("inquiry", ([
			s_skill       : (: ask_special_skill :),
	]));
	setup();

	
	set("chat_chance", 3);
	set("chat_msg", ({
		"朱熹说道：普天之下，莫非王土；率土之滨，莫非王臣。\n",
		"朱熹说道：出家人，小过损益焉；无妄大过，未济咸困之。\n",
		"朱熹说道：大学之道，在明明德。在亲民，在止于至善。 \n",
		"朱熹说道：格物致知，诚意正心，修身齐家，治国平天下。\n",
	}) );
		carry_object("/d/riyuejiao/npc/obj/shuaiyitie");
}

void init()
{
    add_action("do_list","list");
    add_action("do_buy","buy");
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
			return "你的技能已经太高，在下已经无法指点你了。\n";
		
		// lvl <= user_lvl /2
		if (cur_lvl*2 +2 > (int)user->query("level"))
			return "受你的等级限制，我无法继续指点你"+to_chinese(s_skill);
		
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
			message_vision(query("name")+"在$N耳边轻声说了几句锻炼脑筋的方法。\n", user);
			tell_object(user, "你的"+to_chinese(s_skill)+"("+s_skill+")进步了！\n");
			tell_object(user, "你觉得自身的智力也随之增强了。\n");
			return "格物致知，诚意正心。";
		}
	}
	return "什么？";
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/朱"))
		return 0; 
	ob->add_temp("mark/朱", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	object user;
	user = who;
	if (user->query_temp("mark/gold_"+s_skill) && ob->query("money_id") 
			&& ob->value() >= SPECIAL_D->query_money(user, s_skill)* 10000)
	{
		message_vision(query("name")+"同意指点$N一下"+to_chinese(s_skill)+"的问题。\n", user);
		user->delete_temp("mark/gold_"+s_skill);
		user->set_temp("mark/ok_"+s_skill, 1);
		return 1;
	}
	if (!(int)who->query_temp("mark/朱"))
		who->set_temp("mark/朱", 0);
	if (ob->query("money_id") && ob->value() >= 1000) {
		message_vision("朱熹同意指点$N一些读书写字的问题。\n", who);
		who->add_temp("mark/朱", ob->value() / 50);
		return 1;
	}
	return 0;
}
