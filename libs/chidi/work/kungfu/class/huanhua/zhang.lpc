// sample master.c code
// xiake island master.c

inherit BHNPC;
inherit F_MASTER;

#include <ansi.h>
void recover_ob();

void create()
{
	set_name("张长弓", ({"zhang changgong", "zhang", "changgong"}));
	set("nickname", HIY"龙组组长"NOR);
	set("gender", "男性");
	set("age", 26);
	set("long", 
		"他是一个非常英俊的年轻人，略略鼓起的太阳穴显示出他的精湛功力。\n");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 15);
	set("bac", 20);

	set("qi", 1600);
	set("max_qi", 1600);
	set("jingli", 1000);
	set("max_jingli", 1000);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 20);
	
	set("combat_exp", 13000000);
	set("score", 10000);
	
	set_skill("force", 390);
	set_skill("jiuqu-xinfa", 390); 
	set_skill("strike", 390);
	set_skill("feixu-zhang", 390);
	set_skill("dodge", 390); 
	set_skill("huanhua-shenfa", 390); 
	set_skill("sword", 390); 
	set_skill("parry", 390); 
	set_skill("literate", 390); 
	set_skill("confu", 390); 
	set_skill("huanhua-jianfa", 390); 
	
	map_skill("force", "jiuqu-xinfa");
	map_skill("dodge", "huanhua-shenfa");
	map_skill("strike", "feixu-zhang");
	map_skill("parry", "huanhua-jianfa");
	map_skill("sword", "huanhua-jianfa");

	prepare_skill("strike", "feixu-zhang");
	
	create_family("浣花剑派", 5, "弟子");

	setup();

	carry_object("/d/huanhua/npc/obj/jinpao")->wear();
	carry_object("/clone/weapon/changjian")->wield();

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: recover_ob :)
	}) );
	set("add_title","浣花剑庐龙组组员");
}

void recover_ob()
{
	command("yun recover");
	return;
}

void attempt_apprentice(object ob)
{
	object me;
	mapping my_fam, ob_fam;

	me = this_object();

	my_fam = ob->query("family");
	ob_fam = me->query("family");

	if (ob->query("killding"))
	{
		command("say 大胆狂徒，胆敢硬闯萧府，纳命来吧！");
		me->kill_ob(ob);
		ob->kill_ob(me);
		return;
	}

	if ((int)ob->query("shen") <= (-100))
	{
		if (!(my_fam = ob->query("family")) || my_fam["family_name"] != "浣花剑派")
		{
			command("hmm");
			command("say 浣花萧家乃名门正派，岂能容纳邪魔外道，你还不快快滚出剑庐！！！");
			return;
		}
		else
		{
			command("say 你身为浣花弟子却不主张正义，甘入魔道，我浣花容不下你！");
			command("kaichu "+ob->query("id"));
			return;
		}
	}

	if ((!(my_fam = ob->query("family")) || my_fam["family_name"] != "浣花剑派") && (int)ob->query("combat_exp")>200000000)
	{
		command("say "+RANK_D->query_respect(ob)+"已是江湖成名之士，萧家哪敢相留。");
		command("say 对不起了，您请回吧。");
		return;
	}

	if (ob->query("combat_exp")<10000
		|| ob->query_skill("huanhua-shenfa",1)<40
		|| ob->query_skill("huanhua-jianfa",1)<40
		|| ob->query_skill("jiuqu-xinfa",1)<40)
	{
		command("say 不行不行，你功夫太差，杀不了敌人反倒被敌人杀了怎么办？");
		return;
	}

	if ( my_fam )
	{
		if ( my_fam["family_name"] == "浣花剑派" )
		{
			if ( ob_fam["generation"] == my_fam["generation"] )
			{
				command("say 你我乃同辈弟子，切磋切磋倒是可以，拜师却是从何说起？");
				return;
			}
	
			if ( ob_fam["generation"] > my_fam["generation"] )
			{
				message_vision("$N一脸的诚惶诚恐道：究竟弟子犯了什么错，您要和弟子开这样的玩笑。\n", me);
				return;
			}
		}
	}

	command("say 好吧，" + RANK_D->query_respect(ob) +"入我龙组，就好好尽力杀敌，为剑庐出力。");
	command("recruit " + ob->query("id"));
	ob->set("title", "浣花剑派第六代弟子、"HIY"龙组组员"NOR);
	if (!(my_fam = ob->query("family")) || my_fam["family_name"] != "浣花剑派")
		ob->set("pay_money", ob->query("age"));

	return;
}