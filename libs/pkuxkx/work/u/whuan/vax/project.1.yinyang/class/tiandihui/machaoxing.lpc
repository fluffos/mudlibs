#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()

{

	set_name("马超兴", ({ "ma chaoxing", "ma"}));

   	set("title", HIR "天地会"HIY"家后堂"MAG"香主"NOR);	

	set("gender", "男性");

	set("long", "\n他就是天地会洪顺堂堂主，善使一柄大刀。\n");

	set("age", 45);

	set("int", 30);


	set("qi", 1800);
	set("max_qi", 1800);
	set("jing", 1000);
	set("max_jing", 1000);
	set("max_neili", 2500);
	set("neili", 2500);
	set("max_jingli", 1500);
	set("jingli", 1500);

	set("jiali", 150);

	set("shen_type", 1);

	set("combat_exp", 1250000);

	set("attitude", "peaceful");

	set_skill("force", 220);

	set_skill("hand",240);

	set_skill("parry", 240);

	set_skill("dodge", 240);

	set_skill("sword", 200);

	set_skill("blade", 250);

	set_skill("whip", 180);

	set_skill("literate", 180);	

	set_skill("yunlong-shengong", 220);
	set_skill("yunlong-xinfa", 120);

	set_skill("yunlong-shenfa", 240);

	set_skill("wuhu-duanmendao", 250);

	set_skill("yunlong-shou", 240);

	set_skill("yunlong-jian", 200);

	set_skill("yunlong-bian", 180);

	set_temp("apply/attack", 80);

	set_temp("apply/defense", 100);

	set_temp("apply/damage", 85);

	set_temp("apply/armor", 185);

	map_skill("force", "yunlong-shengong");

	map_skill("dodge", "yunlong-shenfa");

	map_skill("parry", "wuhu-duanmendao");

        map_skill("blade","wuhu-duanmendao");

	map_skill("sword", "yunlong-jian");

	map_skill("whip", "yunlong-bian");

        map_skill("hand","yunlong-shou");

        prepare_skill("hand","yunlong-shou");


	create_family("天地会", 2, "弟子");

        set("inquiry", ([

                "陈近南" :  "江湖声值达到十万才能拜总舵主为师。\n",

		"天地会" :  "\n只要是英雄好汉，都可以入我天地会。\n",

                "反清复明" : "去天桥和棺材店仔细瞧瞧吧！\n",

       ]) );

	set("chat_chance_combat", 100);  

	set("chat_msg_combat", ({

		(: command("smile") :),

		(: command("haha") :),

		(: command("chat 这位" + RANK_D->query_respect(this_player())+",你我无冤无仇，何必如此?\n") :),

		(: command("unwield blade") :),

		(: command("unwield blade") :),

		(: command("unwield blade") :),

		(: command("unwield blade") :),

		(: command("unwield blade") :),

		(: command("unwield blade") :),

		(: command("unwield blade") :),

		(: command("unwield blade") :),

		(: command("wield blade") :),

		(: command("wield blade") :),

		(: command("wield blade") :),

		(: command("wield blade") :),

		(: command("wield blade") :),

		(: command("wield blade") :),

		(: command("wield blade") :),

		(: command("wield blade") :),

                (: perform_action, "blade.duan" :),

                (: perform_action, "blade.duan" :),

                (: perform_action, "blade.duan" :),

                (: perform_action, "blade.duan" :),

                (: perform_action, "blade.duan" :),

                (: perform_action, "blade.duan" :),

                (: perform_action, "hand.fuxue" :),

                (: perform_action, "hand.fuxue" :),

                (: exert_function, "recover" :),

                (: exert_function, "recover" :),

		(: command("unwield blade") :),

		(: command("unwield blade") :),

		(: command("unwield blade") :),

		(: command("unwield blade") :),

		(: command("wield blade") :),

		(: command("wield blade") :),

		(: command("wield blade") :),

		(: command("wield blade") :),

		(: command("unwield blade") :),

		(: command("unwield blade") :),

		(: command("unwield blade") :),

		(: command("unwield blade") :),

		(: command("unwield blade") :),

		(: command("unwield blade") :),

                      }) );

	setup();

        carry_object("/d/shaolin/obj/changbian");

        carry_object("/clone/weapon/changjian");

        carry_object("/d/city/obj/gangdao")->wield();

        carry_object("/clone/misc/cloth")->wear();

        add_money("silver",20);

}



void init()

{

        object ob;



        ::init();



        ob = this_player();



        if((int)ob->query("shen") < -1000 && ob->query("family/master_id")=="ma chaoxing")

        {

                command("chat "+ob->query("name")+"!你这等邪恶奸诈之徒，我岂能仍是你的师傅。\n");

                command("expell "+ ob->query("id"));

                this_player()->set("title","云龙门" + RED + "弃徒" NOR);

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

 		command("say 云龙门顶天立地，怎会收你这样的废人？！");

		return;

	   }
	if ((int)ob->query("repute") < 30000) {

		command("say 我云龙门武功盖世，对弟子要求也是极高。");

		command("say " + RANK_D->query_respect(ob) + "若能几件惊天动地的大事，提高自己的武林声望，我肯定收你为徒。");

		return;

	}
	if ((int)ob->query_skill("yunlong-shengong", 1) < 120) {

		command("say 我天地会武功，最重视内功心法。"); 

		command("say " + RANK_D->query_respect(ob) + 

			"是否还应该在云龙神功上多下点功夫？");

		return;

	}

	if ((int)ob->query("shen") >0 && (int)ob->query("shen") < 50000) {

		command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");

		command("say 在德行方面，" + RANK_D->query_respect(ob) +

			"是否还做得不够？");

	return ;

	}

	if (ob->query("score") < 1000)
	{
	   command("say 你自问是否对本门尽力了?");
	   return;
	}
	command("say 好吧，既然" + RANK_D->query_respect(ob) + "也是" +

		"我辈中人，今天就收下你吧。");

	command("recruit " + ob->query("id"));

	if((!(string)ob->query("class")) || ((string)ob->query("class") != "fighter"))

		ob->set("class","fighter");

}

void greeting(object ob)

{
	if(ob->query("shen") < - 100000)
	{
		say( "马超兴怒道：邪魔歪道怎么混到这里来的？\n");
		this_object()->kill_ob(ob);
		return;
	}

               if(random(5)<2) say( "马超兴笑道：这位" + RANK_D->query_respect(ob)

				+ "，可有什么不平之事么？\n");
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("title", HIR "天地会"HIG"青木堂"HIY"护法"NOR);

}
void re_rank(object student)
{
	if( ::recruit_apprentice(student) )
        student->set("title", HIR "天地会"HIG"青木堂"HIY"护法"NOR);
}



