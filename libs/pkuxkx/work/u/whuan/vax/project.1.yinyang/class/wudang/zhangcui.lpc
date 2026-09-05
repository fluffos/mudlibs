#include <ansi.h>
// yu.c 张翠山

inherit NPC;
inherit F_MASTER;

void heal();

void create()
{
        set_name("张翠山", ({ "zhang cuishan", "zhang" }));
       set("nickname", RED "武当五侠" NOR);
        set("long",
                "他就是张三丰的五弟子张翠山。\n"
		"他于武学的悟性极高，是张真人最喜欢的一个弟子，深得武当真传。\n");
        set("title",RED "武当派" NOR + GRN +"真人" NOR);
        set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 32);
        set("con", 28);
        set("dex", 28);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chan" :),
        }) );

        set("chat_chance", 100);
        set("chat_msg", ({
	        (: heal :),
        }));
        set("max_qi", 1500);
        set("max_jing", 800);
        set("neili", 1800);
        set("max_neili", 1800);
        set("jiali", 100);
        set("combat_exp", 500000);
        set("score", 100000);

        set_skill("force", 120);
        set_skill("yinyun-ziqi", 120);
        set_skill("dodge", 160);
        set_skill("tiyunzong", 160);
        set_skill("cuff", 120);
        set_skill("taiji-quan", 120);
        set_skill("parry", 150);
        set_skill("sword", 150);
        set_skill("taiji-jian", 150);
        set_skill("taoism", 80);
        set_skill("literate", 80);

	map_skill("force", "yinyun-ziqi");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");

        create_family("武当派", 2, "弟子");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/whiterobe")->wear();
}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("family/family_name")!="武当派" || (string)ob->query("class")!="taoist") {
                command("say 我武当乃是道家门派。");
                command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜我徒侄谷虚。"); 
                return;
        }
	if ((int)ob->query("shen") < 10000) {
                command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
                command("say " + RANK_D->query_respect(ob) + "若能做出" +
                        "几件侠义之事，我一定收你。");
                return;
        }
        command("say 好吧，既然" + RANK_D->query_respect(ob) + "也是" +
                "我辈中人，今天就收下你吧。");
        command("recruit " + ob->query("id"));
		if ((string)ob->query("gender")!="女性")
			ob->set("title" ,RED "武当派" NOR + GRN "道长" NOR);
		else
                        ob->set("title" ,RED "武当派" NOR + GRN "女道长" NOR);
}

void init()
{

        object ob;
        mapping fam;

        ::init();

        ob = this_player();
        if ( (int)ob->query("shen") <1000 && (string)ob->query("family/master_id") == "zhang cuishan")
	{
		command("say 你多次杀人越货，胡作非为，我岂能仍是你的师傅。\n");
		command("expell "+ ob->query("id"));
	}
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
