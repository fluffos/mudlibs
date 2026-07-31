// danqing-sheng.c 
inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("丹青生", ({ "danqing sheng", "sheng" }));
        set("title", "梅庄四庄主");
        set("long",
                "他就是梅庄四位庄主排行第四的丹青生。\n"
                "身穿一件干干净净的青色长袍。\n"
                "他已年愈四旬，身材瘦长，满脸红光。恬淡冲和，沉默寡言。\n");
        set("gender", "男性");
        set("age", 40);
        set("class", "scholar");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 11000);
        set("max_jing", 11000);
        set("neili", 12000);
        set("max_neili", 12000);
        set("jiali", 50);
        set("combat_exp", 800000);
        set("shen", 15000);
        set("score", 60000);

        set_skill("painting", 300);
        set_skill("force", 100);
        set_skill("wuzheng-xinfa", 120);
        set_skill("dodge", 100);
        set_skill("piaoyibu", 110);
        set_skill("parry", 120);
        set_skill("sword", 120);
        set_skill("wuyun-jian", 100);
        set_skill("literate", 130);
set_skill("kuihua-xinfa", 200);
        map_skill("force", "wuzheng-xinfa");
        map_skill("dodge", "piaoyibu");
        map_skill("parry", "wuyun-jian");
        map_skill("sword", "wuyun-jian");
        set_skill("pomopima-jian",300);
        set_skill("wuzheng-xinfa",300);
                map_skill("force", "pomopima-jian");
        map_skill("sword", "pomopima-jian");
        create_family("梅庄", 1, "庄主");
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
        set("inquiry", ([
                "令牌" : (: ask_me :),
        ]));

        set("item_count", 1);

        setup();
        carry_object("/clone/weapon/changjian")->wield();

}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("shen") < 0) {
                command("say 我梅庄虽然不是什么名门正派, 但择徒也极为严格。");
                command("say 在品行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }
        if ((int)ob->query_skill("wuzheng-xinfa",1) < 30) {
                command("say 我是不轻易收徒的。");
                command("say 在我梅庄的内功上，" + RANK_D->query_respect(ob) +
                        "是否还应该多下点功夫？");
                return;
        }
        command("say 好吧，在下就收下你了。");
        command("recruit " + ob->query("id"));
}

string ask_me()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "梅庄")
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
        if (query("item_count") < 1)
                return "你来晚了，梅花令牌不在此处。";
        add("item_count", -1);
        ob = new(__DIR__"obj/lingpai");
        ob->move(this_player());
        return "好吧，这块梅花令牌就交给你保管了。";
}

