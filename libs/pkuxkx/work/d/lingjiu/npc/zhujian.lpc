// /NPC zhujian.c
// By adx @ CuteRabbit 22:21 99-3-19

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("竹剑", ({ "zhu jian", "zhu"}));
	set("long",
	    "这是个容貌姣好的女子, 瓜子脸蛋,\n"+
	    "眼如点漆, 清秀绝俗.\n"+
	    "你总觉得在哪见过她.\n");
	set("gender", "女性");
	set("per", 27);
	set("age", 18);
	set("shen_type",0);
	set("attitude", "peaceful");
	set("per", 31);

	//set("class", "officer");
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("shen_type",1);

	set("qi", 800);
	set("max_qi", 800);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 50);

	set("combat_exp", 500000);
	set("score", 1000);
	set_skill("force", 80);
//	set_skill("unarmed", 150);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("hand",80);
	set_skill("strike", 80);
	set_skill("sword",80);

	set_skill("zhemei-shou",80);
	set_skill("liuyang-zhang",80);
	set_skill("changhen-jian",100);
	set_skill("lingbo-weibu",100);
	set_skill("bahuang-gong", 80);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "lingbo-weibu");
//	map_skill("unarmed", "liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "changhen-jian");

	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand","zhemei-shou"); 
	create_family("灵鹫宫",3,"弟子");
	set("chat_chance_combat", 50);
/*	set("chat_msg_combat", ({
		(: perform_action, "strike.zhong" :),
		(: perform_action, "hand.duo" :),
		(: perform_action, "sword.changhen" :),
		(: command("unwield jian") :),
		(: command("wield jian") :),
		(: exert_function, "recover" :),
		(: exert_function, "recover" :),
		(: command("unwield jian") :),
		(: command("wield jian") :),
            }) );
*/
	setup();
 	carry_object("/clone/weapon/jian")->wield();
	carry_object("/d/lingjiu/obj/qianhuangyi")->wear();
        add_money("silver",15);
}
void init()
{
	object me, ob;
	mapping fam;

	::init();
	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight")
	&& ((fam = ob->query("family")) && fam["family_name"] != "灵鹫宫" ))
	{
   	   if (!ob->query_temp("lingjiu/ask_apprentice")){
		if( !ob->query_temp("warned") ) {
		command("say 尊主有令：外人不得进入灵鹫宫，速速离开！");
			ob->set_temp("warned", 1);
		}
		else if( ob->query_temp("stay")<5 ) ob->add_temp("stay",1);
		else {
			command("say 大胆狂徒，竟敢擅闯灵鹫宫！！！\n");
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	   }
	}
}
void attempt_apprentice(object ob)
{
   
	if ((string)ob->query("gender")!="女性")
           {
 		command("say 你找死啊!\n");
		return;
	   }

	command("say 我还不能收徒，你可以去拜程副首领。\n");
	ob->set_temp("lingjiu/ask_apprentice",1);
	
	return;
}
