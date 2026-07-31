// /d/yixing/npc/cl_bei.c 贝海石
// Last Modified by winder on Jul. 12 2002
#include <ansi.h>;
inherit NPC;
int ask_me();
#include <ansi.h>

void create()
{
	set_name("贝海石", ({ "bei haishi", "bei" }));
	set("nickname", HIG"着手成春"NOR);
	set("party/party_name", HIC"长乐帮"NOR);
	set("party/rank", "总管");
	set("long", 
		"他是一个身穿黄衫的老人，看上去脸色苍白，说话有气无力，\n"
		"还不停的咳嗽着，便似身患重病一般。\n");
	set("gender", "男性");
	set("age", 50);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 25);
	set("int", 30);
	set("con", 28);
	set("dex", 28);

  set("qi", 38000);
        set("max_qi", 38000);
        set("jing", 38000);
        set("max_jing", 38000);
        set("neili", 51500);
        set("max_neili", 51500);
        set("jiali", 50);
        set_skill("parry", 380);
	set_skill("force", 380);
	set_skill("unarmed", 380);
	set_skill("dodge", 380);
	set_skill("taixuan-gong", 550);
	set_skill("feixian-steps", 580);
	set_skill("shenzhao-jing", 580);
	map_skill("force", "shenzhao-jing");
	map_skill("parry", "taixuan-gong");
	map_skill("unarmed", "shenzhao-jing");
	map_skill("dodge", "feixian-steps");
        set("combat_exp", 3500000);
        set("score", 200000);
set("max_neili",50000);
        set("neili",50000);
        set("max_qi",36800);
        set("max_jing",36800);
        set("jing",36800);
        set("qi",36800);
        set("eff_jingli",38000);
        set("jingli",38000);
        set("jiali",100);
	set("szj/passed", 1);
	set("szj/over200", 1);
	set("book_count", 1);
	set("chat_chance_combat", 90);
       set("chat_msg_combat", ({
                (: perform_action, "unarmed.wu" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.jing" :),
                (: perform_action, "parry.xuan" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.taixuan" :),
               
        }) );
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 2000);
	set_temp("apply/damage", 2000);


	set("inquiry", ([
		"长乐帮" : "长乐帮的具体事务由我总管。",
		"入帮" : "你去问帮主吧。",
		"武功" : "帮主老人家的武功比我强多了，你还是向帮主学吧。",
		"香主" : "各位香主的任命由帮主老人家说了算。",
		"司徒横" : "我对我们帮主老人家的景仰之情，有如滔滔江水连绵不绝。",
		"帮主" : "我家帮主司徒大爷乃威镇江南的“东霸天”也。",
	"石中玉" : (: ask_me :),
	]));

	setup();

	carry_object("/clone/misc/cloth")->wear();
}

int ask_me()
{
	int i;
        object ob;
	object who = this_player();
	object where = environment(who);
	if(!who->query_temp("book1131"))
	{
		message_vision("$N对$n说道： 石中玉是谁？ 我不知道了。\n",this_object(),who);
  
		return 1;	
	}

	if(!who->query_temp("book1132"))
	{
		message_vision("$N对$n说道： 展飞那叛徒的话，你也信?\n",this_object(),who);
  
		return 1;	
	}
message_vision("$N对$n即然你一切都知道了，你就去死吧。\n",this_object(),who);
who->set_temp("book1133",1);
kill_ob(who);                    
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
  	if(((int)who->query("jinyong/book11")>=3))
	{
//::die();	
	}
        else if(who) {
  	if(((int)who->query("jinyong/book11")==2) && who->query_temp("book1133"))
{
		message_vision("$N说道：我不会败的，不 不 不！凌霄城白城主，会帮我报仇的。\n" NOR,this_object());
		i = 500+random(1000);
		who->set("jinyong/book11",3);
		who->add("combat_exp",i+12000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		tell_object (who,"你赢得了"+chinese_number(i+12000)+"点经验"+
		           chinese_number(i*18)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
		who->save();
}
        }
	::die();
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      