//杨铁心
//

#include <ansi.h>

inherit NPC;
inherit F_DEALER;
inherit F_MASTER;


string s_skill;
string ask_special_skill();

void create()
{
        set_name("杨老板", ({ "yang tiejiang", "yang" }));
        set("title", "枪铺");
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 45);
        set("long",
                "杨老板是一个精明的生意人,靠卖仿制的夺魄枪赚了不少钱。\n");
        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        set_temp("apply/damage", 15);
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set("vendor_goods", ({
                "/d/yuewangmu/obj/falsedpqiang",
                "/d/yuewangmu/obj/dmqiang",
                "/d/yuewangmu/obj/gangqiang",
                "/d/yuewangmu/obj/changqiang",
                "/d/yuewangmu/obj/hyqiang",
           }));
		// 特别技能指导能力
		s_skill = "master-spear";
        set("inquiry", ([
                s_skill       : (: ask_special_skill :),
        ]) );
        setup();
}
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}


string ask_special_skill()
{
	object user;
	int cur_lvl, spear_lvl;
	
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
		
		if (user->query("nation")!= "苗家部族")
			return user->query("nation")+"怕是难以修习"+to_chinese(s_skill)+"。";
		
		spear_lvl = user->query_skill("spear",1)/20;
		if (spear_lvl < user->query_skill("halberd",1)/20) spear_lvl = user->query_skill("halberd",1)/20;
		if (spear_lvl < user->query_skill("fork",1)/20) spear_lvl = user->query_skill("fork",1)/20;
		
		if (cur_lvl >= spear_lvl)
			return "你的基本功太差了，没有办法继续学习"+to_chinese(s_skill)+"。你先去加强修炼"+ to_chinese("spear") + "(spear)、"+to_chinese("halberd")+"(halberd)或者"+to_chinese("fork")+"(fork)吧。";
			
		if (!SPECIAL_D->query_level(user, "master-dex"))
			return "你先要修习"+to_chinese("master-dex")+"(master-dex)才能修炼"+to_chinese(s_skill)+"。";
			
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
			message_vision(query("name")+"在$N耳边轻声说了几句枪法的诀窍。\n", user);
			tell_object(user, "你的"+to_chinese(s_skill)+"("+s_skill+")进步了！\n");
			tell_object(user, "你觉得使枪戟的能力也随之增强了。\n");
			return "练好枪法后，一定要为岳王爷报仇！";
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

