// gsz.c 公孙止
// By River 99.5.25
#include <ansi.h>
inherit NPC;
string ask_gu();
void create()
{
	set_name("公孙止", ({ "gongsun zhi", "gongsun", "zhi" }));
	set("long","面目英俊，透出轩轩高举之概，只是面色蜡黄，容颜枯槁。\n");
        set("title",HIW"绝情谷谷主"NOR);
	set("gender", "男性");
	set("age", 45);
	set("attitude", "friendly");
	set("shen", -3000);
set("pubmaster",1);
	set("str", 55);
	set("int", 54);
	set("con", 58);
	set("dex", 56);
        set("per", 50);
        set("unique", 1);

	set("max_qi", 28500);
	set("max_jing", 28000);
	set("neili", 58000);
	set("max_neili", 58000);
        set("jing", 22000);
        set("max_jing", 22000);
        set("eff_jing", 22000);
	set("jiali", 80);
	set("combat_exp", 5500000);
 
        set_skill("sword", 300);      
        set_skill("blade", 300);
        set_skill("force", 300);      
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("guiyuan-tunafa", 300);
        set_skill("literate", 200); 
        set_skill("shuishangpiao", 200);
        set_skill("tiezhang-zhangfa", 200);
        set_skill("strike",200);
        set_skill("sword", 200);
	set_skill("heijian-jindao", 380);

        map_skill("force", "guiyuan-tunafa");
        map_skill("dodge", "shuishangpiao");
        map_skill("strike", "tiezhang-zhangfa");
        map_skill("parry", "heijian-jindao");
	map_skill("sword", "heijian-jindao");
	map_skill("blade", "heijian-jindao");
        prepare_skill("strike", "tiezhang-zhangfa");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.daojian" :),
                (: perform_action, "sword.jianqi" :),
                (: perform_action, "sword.lianhuan" :),
                (: perform_action, "sword.nizhuan" :),
                (: perform_action, "sword.yinyang" :),
                (: perform_action, "strike.tianlei" :),
                (: perform_action, "strike.tiezhangxianglong" :),
                (: perform_action, "strike.zhangdao" :),
        }) );
     set ("chat_chance",50);
     set ("chat_msg", ({
                      (: random_move :)
                      }) );
        set("inquiry", ([
            "绝情丹": "丹药无多，而且也很难炼制，非万不得已。。。",
            "绝情谷": (: ask_gu :),
        ]) );
        set_temp("apply/dodge", 100);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 500);
	setup();
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/weapon/gangdao");
	carry_object("/clone/misc/cloth")->wear();
}

string ask_gu()
{
       object me,ob;
       me=this_object();
       ob=this_player();
       if(ob->query("combat_exp") < 200000)
         return RANK_D->query_respect(ob)+"功夫还太弱，绝情谷中甚为危险，还是不要在此久留了。";      
         ob->set_temp("gsz_agree", 1);
         return RANK_D->query_respect(ob)+"既然对绝情谷甚有兴趣，就请随便看看吧。";
}


int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timeh"))      
		who->set_temp("learn_timeh", 0);

	if( !ob->query("money_id") )
		return 0;		


	if(who->query_skill("heijian-jindao",1)<30)
		i=ob->value() / 150;
	else
	{
		if(who->query_skill("heijian-jindao",1)<60)
			i=ob->value() / 200;
		else
		{
			if(who->query_skill("heijian-jindao",1)<100)
				i=ob->value() / 300;
			else
				i=ob->value() / 500;
		}
	}
if (random(3)==0)
{
if (i < 1) i=0;
	who->add_temp("learn_timeh",i);

      message_vision("公孙止对$N说道：既然你诚心想学我的武功，我就成全成全你吧。\n",who);
}
      message_vision("公孙止对$N说道：谢谢了，正好本谷缺钱用。\n",who);
	return 1;
}

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeh") <= 0) return 0;
else         
ob->add_temp("learn_timeh",-1);
return 1;
}
void unconcious()
{
        die();
}

void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;

  	if(who->query("jinyong/book10")==3 && who->query_temp("book1041"))
{

		message_vision("$N说道：裘千尺这个贱人！\n" NOR,this_object());
		i = 1200+random(2000);
		who->set("jinyong/book10",4);
		who->add("combat_exp",i+13000);
		who->add("potential",i*19);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"胆色过人，义惩青城恶霸。");
		tell_object (who,"你赢得了"+chinese_number(i+13000)+"点经验"+
		           chinese_number(i*19)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
		tell_object (who,"从附近绝情谷弟子身上知道了 金轮法王一伙人去全真教了！\n");


		who->save();
}

	
::die();
}                                                                              