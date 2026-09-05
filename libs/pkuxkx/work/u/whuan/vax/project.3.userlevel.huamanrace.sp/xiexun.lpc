// xiexun.co.c
inherit NPC;
inherit F_MASTER;
void heal();
#include <ansi.h>
string s_skill;
string ask_special_skill();
void create()
{
        set_name("谢逊", ({ "xie xun", "xie" }));
        set("nickname", YEL"金毛狮王"NOR);
        set("title",GRN "明教" NOR + YEL +"法王" NOR);
        set("long","他是明教四大法王之一－－金毛狮王。身着一件黄衫，满面红光。\n
"
                   "他有着一头的黄发，只因早年修习特异武功之故。他武艺高强，在 \
n"
                   "明教中是数一数二的人物。\n");
         set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 27);
        set("int", 28);
        set("con", 28);
        set("dex", 30);
        set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));
        set("max_qi", 2000);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 50);
       set("combat_exp", 500000);
        set_skill("force", 110);
        set_skill("jiuyang-shengong", 100);
        set_skill("shenghuo-xinfa", 100);
        set_skill("dodge", 110);
        set_skill("parry", 120);
        set_skill("jinwu-dao",120);
        set_skill("datengnuo-bufa", 100);
        set_skill("blade", 110);
        set_skill("literate", 100);
        set_skill("shenghuo-shengong", 50);
        set_skill("cuff",150);
        map_skill("blade","jinwu-dao");
         map_skill("cuff","qishang-quan");
        map_skill("force", "jiuyang-shengong");
        map_skill("parry", "shenghuo-shengong");
        map_skill("dodge", "datengnuo-bufa");
        prepare_skill("cuff","qishang-quan");
        create_family("明教", 20, "弟子");
		
		// 特别技能指导能力
		s_skill = "master-blade";
        set("inquiry", ([
                s_skill       : (: ask_special_skill :),
        ]) );
        setup();
        carry_object("/d/mingjiao/obj/huangshan")->wear();
        carry_object("/d/mingjiao/obj/gangdao")->wield();
}


string ask_special_skill()
{
	object user;
	int cur_lvl, blade_lvl;
	
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
		
		if (user->query("nation")!= "东瀛浪人")
			return user->query("nation")+"怕是难以修习"+to_chinese(s_skill)+"。";
		
		blade_lvl = user->query_skill("blade",1)/20;
		if (blade_lvl < user->query_skill("axe",1)/20) blade_lvl = user->query_skill("axe",1)/20;
		
		if (cur_lvl >= blade_lvl)
			return "你的基本功太差了，没有办法继续学习"+to_chinese(s_skill)+"。你先去加强修炼"+ to_chinese("blade") + "(blade)或者"+to_chinese("axe")+"(axe)吧。";
			
		if (!SPECIAL_D->query_level(user, "master-str"))
			return "你先要修习一些"+to_chinese("master-str")+"(master-str)才能修练"+to_chinese(s_skill)+"。";
			
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
			message_vision(query("name")+"在$N耳边轻声说了几句持刀的法门。\n", user);
			tell_object(user, "你的"+to_chinese(s_skill)+"("+s_skill+")进步了！\n");
			tell_object(user, "你觉得使刀的能力也随之增强了。\n");
			return "另外我的狮吼功也是相当厉害～～";
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

void attempt_apprentice(object ob)
{
         if ((string)ob->query("family/family_name")!="明教" )
        {
                command("say 本王不收外派弟子。");
  command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜颜垣。");
                return;
        }
        if ((int)ob->query("score")<500) {
               command("heng"+ob->query("id"));
               command("本王最恨欺师灭祖之人,我怎能收你?");
                return;
           } 
        if ((int)ob->query_skill("jiuyang-shengong", 1) < 30) {
                command("say 你的九阳神功太低了，无法修习我的功夫。");
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在九阳神功上多下点功夫？");
                return;
        }
        if((int)ob->query("betrayer")>=10)
        {
   command("say "+RANK_D->query_respect(ob)+"多次背信弃义，本王怎可收你。");
                return;
        }
        if ((int)ob->query("shen") < 5000) {
                command("say 我谢逊乃顶天立地的好汉，我的弟子应该扶危济困.");
                command("say " + RANK_D->query_respect(ob) + "若能做出" +
                        "几件侠义之事，本王一定收你。");
                return;
        }
     command("say 好吧，"+RANK_D->query_respect(ob)+"！本王就收下你了！\n");
           command("recruit "+ob->query("id"));
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                      ob->set("title",GRN "明教" NOR + YEL +"旗主" NOR);
                        return;
}
void re_rank(object student)
{
                        student->set("title",GRN "明教" NOR + YEL +"旗主" NOR);
                        return;
}
void init()
{
        object ob;
        mapping fam;
        ob = this_player();
        if ( (int)ob->query("shen") <0 && ob->query("family/master_id") == "xie xun")
        {
   command("say 你多次杀人越货，胡作非为，本王岂能仍是你的师傅。\n");
   command("expell "+ ob->query("id"));
        }
        ::init();
}
void heal()
{
        object ob=this_object();
        if (ob->query("eff_qi") < ob->query("max_qi"))
        {
                command("exert heal");
                command("enforce 50");
                return;
        }
        if (ob->query("qi") < ob->query("eff_qi"))
        {
                command("exert recover");
                return;
        }
        if (ob->query("jing") < ob->query("eff_jing"))
                command("exert regenerate");
        return;
}
