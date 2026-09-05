// weiyixiao.co.c
// changed by fast
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void heal();

string s_skill;
string ask_special_skill();
void create()
{
        set_name("韦一笑", ({ "wei yixiao", "wei" }));
        set("nickname", HIC"青翼蝠王"NOR);
        set("title",GRN "明教" NOR + YEL +"法王" NOR);
        set("long","他是明教四大法王之一－－青翼幅王韦一笑。身着一件青衫。他脸色
泛青，\n"
                   "可能是修习寒冰绵掌之故。他的轻功独步天下，凭此一技在江湖上闯
出了 \n"
                   "青翼幅王的名声。\n");
         set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 27);
        set("int", 28);
        set("con", 28);
        set("dex", 30);
        set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));
set("chat_chance_combat", 100);
set("chat_msg_combat", ({
(: perform_action , "strike.shixue" :),
}));
        set("max_qi", 2000);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 100);
          set("combat_exp",400000);
        set_skill("force", 110);
        set_skill("jiuyang-shengong", 100);
        set_skill("shenghuo-xinfa", 100);
        set_skill("dodge", 200);
        set_skill("parry", 120);
        set_skill("hanbing-zhang",100);
        set_skill("datengnuo-bufa", 200);
        set_skill("strike", 110);
        set_skill("literate", 100);
        set_skill("shenghuo-shengong", 50);
        map_skill("force", "jiuyang-shengong");
        map_skill("parry", "shenghuo-shengong");
        map_skill("dodge", "datengnuo-bufa");
        map_skill("strike", "hanbing-zhang");
        prepare_skill("strike","hanbing-zhang");
        create_family("明教", 20, "弟子");
		
		// 特别技能指导能力
		s_skill = "master-dex";
        set("inquiry", ([
                s_skill       : (: ask_special_skill :),
        ]));
        setup();
        carry_object("/d/mingjiao/obj/qingshan")->wear();
}
void init()
{
        object ob;
        mapping myfam;
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                myfam = (mapping)ob->query("family");
                if ((!myfam || myfam["family_name"] != "明教") &&
                        (!wizardp(ob))) {
                        remove_call_out("do_killing");
                        call_out("do_killing",4,ob);
                }
        }
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
			message_vision(query("name")+"在$N耳边轻声说了几句轻身的法门。\n", user);
			tell_object(user, "你的"+to_chinese(s_skill)+"("+s_skill+")进步了！\n");
			tell_object(user, "你觉得自身的身子轻快了些许。\n");
			return "赶快躲开，我又要寒毒发作吸人血了。";
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

void do_killing(object ob)
{
        if (!ob || environment(ob) != environment())
                return;
        this_object()->kill_ob(ob);
}
void attempt_apprentice(object ob)
{
         if ((string)ob->query("family/family_name")!="明教" )
        {
                command("say 我不收外派弟子。");
  command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜颜垣。");
                return;
        }
        if ((int)ob->query_skill("jiuyang-shengong", 1) < 30) {
                command("say 你的九阳神功太低了，无法修习我的功夫。");
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在九阳神功上多下点功夫？");
                return;
        }
       if ((int)ob->query("shen") >-10000)
        {
                command("say 我韦一笑最看不过眼满肚子伪善道德的人。");
                command("say " + RANK_D->query_respect(ob) + "若能杀他" +
                        "几个伪君子，我一定收你。");
                return;
        }
        if ((int)ob->query("score") < 500)
          {
             command("say 我不收对师门不忠的人!");
             command("heng");
           return;
         }
        if((int)ob->query("betrayer")>=10)
        {
   command("say "+RANK_D->query_respect(ob)+"多次背信弃义，我怎可收你。");
                return;
        }
     command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
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
