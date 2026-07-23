// huangzhong-gong.c
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("黄钟公", ({ "huangzhong gong", "gong" }));
        set("title", "梅庄大庄主");
        set("long",
                "他就是梅庄四位庄主排行第一的黄钟公。\n"
                "身穿一件干干净净的黄色长袍。\n"
                "他已年愈六旬，身材中等，面容和蔼可亲。\n");
        set("gender", "男性");
        set("age", 62);
        set("class", "scholar");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);


        set("max_qi", 21000);
        set("max_jing", 21000);
        set("neili", 21000);
        set("max_neili", 21000);
        set("jiali", 100);
        set("combat_exp", 3500000);
        set("shen", 15000);
        set("score", 60000);
	set_skill("songshan-jian", 380);
  set_skill("luoyan-jian",380);
  set_skill("shiba-pan",380);
  set_skill("liuhe-dao",380);
  set_skill("hengshan-jian",380);
        set_skill("force", 220);
              set_skill("luteplaying", 350);  
        set_skill("wuzheng-xinfa", 350);
        set_skill("dodge", 220);
        set_skill("piaoyibu", 350);
        set_skill("parry", 150);
        set_skill("sword", 220);
        set_skill("wuyun-jian", 350);
        set_skill("literate", 220);
        set_skill("kuihua-xinfa", 200);
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
        map_skill("force", "wuzheng-xinfa");
        map_skill("dodge", "piaoyibu");
        map_skill("parry", "wuyun-jian");
        map_skill("sword", "wuyun-jian");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({

                (: perform_action, "sword.shan" :),
                (: perform_action, "sword.zhu" :),
                (: perform_action, "sword.yin" :),
         
             
        }) );
        create_family("梅庄", 1, "庄主");
        setup();
        carry_object("clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query_skill("wuzheng-xinfa",1) < 120) {
                command("say 我是不轻易收徒的。");
                command("say 在我梅庄的内功上，" + RANK_D->query_respect(ob) +
                        "是否还应该多下点功夫？");
                return;
        }
        command("say 好吧，在下就收下你了。");
        command("recruit " + ob->query("id"));
}

