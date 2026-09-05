// xuanzhen.c 
// modified by iszt@pkuxkx, 2007-02-08

#include <ansi.h>
#include <title.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("玄真道长", ({ "xuan zhen", "xuan", "zhen" }));
	set("title", HIR "天地会"HIG"青木堂"HIY"护法"NOR);
	set("gender", "男性");
	set("long", "\n这位沉默寡言的道人，便是天地会青木堂护法。\n"
		"他是青木堂数一数二的好手，一柄长剑使得出神入化。\n");

	set("age", 55);

	set("int", 30);

	set("qi", 1500);
	set("max_qi", 1500);
	set("jing", 800);
	set("max_jing", 800);
	set("max_neili", 1800);
	set("neili", 1800);
	set("max_jingli", 800);
	set("jingli", 800);

	set("jiali", 100);
	set("shen_type", 1);
	set("combat_exp", 950000);
	set("attitude", "peaceful");

	set_skill("force", 180);
	set_skill("literate", 150);
	set_skill("parry", 180);
	set_skill("dodge", 180);
	set_skill("sword", 200);
	set_skill("hand", 140);
	set_skill("claw", 140);
	set_skill("cangming-gong", 180);
	set_skill("lingding-piao", 180);
	set_skill("danxin-jian", 200);
	set_skill("fulong-shou", 140);
	set_skill("yunlong-zhua", 140);
	set_temp("apply/attack", 70);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 80);
	set_temp("apply/armor", 180);
	map_skill("force", "cangming-gong");
	map_skill("dodge", "lingding-piao");
	map_skill("parry", "danxin-jian");
	map_skill("sword", "danxin-jian");
	map_skill("hand", "fulong-shou");
	map_skill("claw", "yunlong-zhua");
	prepare_skill("hand", "fulong-shou");
	prepare_skill("claw", "yunlong-zhua");

	create_family("天地会", 3, "弟子");

	set("inquiry", ([
		"陈近南" :  "为人不识陈近南，便称英雄也枉然。",
		"天地会" :  "只要是英雄好汉，都可以入我天地会。",
		"反清复明" : "去屠宰场和棺材店仔细瞧瞧吧！",
       ]) );

	set("chat_chance_combat", 100);  
	set("chat_msg_combat", ({
		(: command("smile") :),
		(: command("haha") :),
		(: CHANNEL_D->do_channel(this_object(), "bd", "这位" + RANK_D->query_respect(this_player())+",你我无冤无仇，何必如此？") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield bian") :),
		(: command("wield bian") :),
		(: command("wield bian") :),
		(: command("wield bian") :),
		(: perform_action, "sword.xian" :),
		(: perform_action, "sword.xian" :),
		(: perform_action, "sword.xian" :),
		(: perform_action, "hand.an" :),
		(: perform_action, "hand.an" :),
		(: exert_function, "recover" :),
		(: exert_function, "recover" :),
		(: command("unwield bian") :),
		(: command("unwield bian") :),
		(: command("unwield bian") :),
		(: command("unwield bian") :),
	}) );

	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;

	::init();

	ob = this_player();

	if((int)ob->query("shen") < -1000 && ob->query("family/master_id")=="xuan zhen")
	{
		CHANNEL_D->do_channel(this_object(), "jh", ob->query("name")+"!你这等邪恶奸诈之徒，我岂能仍是你的师傅。");
		command("expell "+ ob->query("id"));
		this_player()->set("title","天地会" + RED + "弃徒" NOR);
//title系统记录玩家title by seagate@pkuxkx
	  ob->set_title(TITLE_RANK, ob->query("title"));
	}
	else
	{
		remove_call_out("greeting");
		call_out("greeting", 1, this_player());
	}
}


void attempt_apprentice(object ob)
{
	if (ob->query("family/family_name") != "天地会")
	{
		command("say 想加入天地会要脚踏实地，" + RANK_D->query_respect(ob) + "先去拜关夫子吧！\n");
		return;
	}
	if((string)ob->query("family/master_id") == "chen jinnan")
	{
		command ("say 这位" + RANK_D->query_respect(ob) + "既已得到总舵主真传，又何必来找我呢?");
		return;
	}		
	if((string)ob->query("gender")=="无性")
	{
		command("say 天地会顶天立地，怎会收你这样的废人？！");
		return;
	}
	if ((int)ob->query("repute") < 10000)
	{
		command("say 我天地会武功盖世，对弟子要求也是极高。");
		command("say " + RANK_D->query_respect(ob) + "若能做几件惊天动地的大事，提高自己的武林声望，我肯定收你为徒。");
		return;
	}
	if ((int)ob->query_skill("cangming-gong", 1) <60)
	{
		command("say 我天地会武功，最重视内功心法。"); 
		command("say " + RANK_D->query_respect(ob) + "是否还应该在浩气苍冥功上多下点功夫？");
		return;
	}

	if ((int)ob->query("shen") >0 && (int)ob->query("shen") < 10000)
	{
		command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) + "是否还做得不够？");
		return ;
	}
	if (ob->query("score") < 500)
	{
		command("say 你自问是否对本门尽力了?");
		return;
	}
	command("say 好吧，既然" + RANK_D->query_respect(ob) + "也是我辈中人，今天就收下你吧。");
	command("recruit " + ob->query("id"));

	if((!(string)ob->query("class")) || ((string)ob->query("class") != "fighter"))
		ob->set("class","fighter");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

        if(ob->query("shen") < - 1000000)
	{
		say( "玄真说道：你这" + RANK_D->query_rude(ob)+ "到这里来干什么？\n");
		this_object()->kill_ob(ob);
		return;
	}

	if(ob->query("repute") >= 200000)

		switch(random(3))
		{
		case 1:
			if (base_name(environment(this_object())) == "/d/luoyang/andao1")
			{
				say( "玄真笑道：这位" + RANK_D->query_respect(ob) + "，"
					"我带你去青木堂吧。\n");
				ob->move("/d/luoyang/qingmutang");
				message_vision("$N来到了青木堂大厅。\n",ob);
			}
			break;
		default:
			say( "玄真说道：这位" + RANK_D->query_respect(ob) + "，请自便。\n");
			break;
	}
	else say( "玄真笑道：这位" + RANK_D->query_respect(ob) + "，到这儿来干什么？\n");

}
void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
	{
	  ob->set("title", HIR "天地会"HIG"青木堂"NOR"会众");
//title系统记录玩家title by seagate@pkuxkx
	  ob->set_title(TITLE_RANK, ob->query("title"));
	}
}

void re_rank(object student)
{
	student->set("title", HIR "天地会"HIG"青木堂"NOR"会众");
//title系统记录玩家title by seagate@pkuxkx
	student->set_title(TITLE_RANK, student->query("title"));
}
