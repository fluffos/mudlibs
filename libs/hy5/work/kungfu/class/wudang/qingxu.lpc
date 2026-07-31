// qingxu.c 清虚

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("清虚道长", ({ "qingxu daozhang", "qingxu","daozhang" }));
        set("long",
                "他就是宋远桥的弟子清虚道长。\n"
                "他今年三十八岁，主管武当派后山的俗事。\n");
        set("gender", "男性");
        set("age", 38);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("class", "taoist");
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

        set("max_qi", 1000);
        set("max_jing", 800);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 30);
        set("combat_exp", 60000);
        set("score", 8000);

        set_skill("force", 50);
        set_skill("taiji-shengong", 50);
        set_skill("dodge", 50);
        set_skill("tiyunzong", 40);
        set_skill("unarmed", 60);
        set_skill("taiji-quan", 60);
        set_skill("parry", 50);
        set_skill("sword", 60);
        set_skill("wudang-jian", 40);
        set_skill("taoism", 50);
        set_skill("literate", 50);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "wudang-jian");
        map_skill("sword", "wudang-jian");

        create_family("武当派", 3, "弟子");
        set("class", "taoist");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("guarded") < 1) {
                command("say " + RANK_D->query_respect(ob) +
                        "你对我武当派尽了多少心力，有几分忠心呢？");
                return;
        }
        if ((int)ob->query("shen") < 0) {
                command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }
        command("say 好吧，贫道就收下你了。");
        command("recruit " + ob->query("id"));
}
