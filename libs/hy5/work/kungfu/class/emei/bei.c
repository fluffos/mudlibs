// bei.c 贝锦仪

inherit NPC;
inherit F_MASTER;
int ask_for_ji();
void create()
{
        set_name("贝锦仪", ({ "bei jinyi","bei","jinyi"}));
        set("long",
                "她是峨嵋派的第四代俗家弟子。\n");
        set("gender", "女性");
        set("age", 21);
        set("attitude", "peaceful");
        set("class", "fighter");
        set("shen_type", 1);

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 30);

        set("max_qi", 1000);
        set("max_jing", 500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jingli", 1500);
        set("max_jingli", 1500);
        set("inquiry",([
            "倚天剑"  : "师父把她交给纪师姊了。",
            "纪晓芙"  : (: ask_for_ji :),
        ]));

        set("combat_exp", 150000);
        set("score", 1000);
        set_skill("throwing", 30);
        set_skill("persuading", 50);
        set_skill("force", 80);
        set_skill("dodge", 80);
        set_skill("finger", 85);
        set_skill("parry", 70);
        set_skill("strike", 60);
        set_skill("sword", 60);
        set_skill("jinding-zhang", 60);
        set_skill("tiangang-zhi", 85);
        set_skill("huifeng-jian", 60);
        set_skill("zhutian-bu", 80);
        set_skill("linji-zhuang", 80);
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("parry","huifeng-jian");

        create_family("峨嵋派", 4, "弟子");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/city/obj/cloth.c")->wear();
}

void attempt_apprentice(object ob)
{

        if ((int)ob->query("shen") < 0) {
                command("say 我峨嵋乃是堂堂名门正派，对弟子要求极严。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }
        command("say 好吧，我就收下你了。");
        command("recruit " + ob->query("id"));
}
int ask_for_ji()
{
    object ob;
    ob = this_player();
    tell_object(ob,"贝锦仪说道：纪晓芙在舍身崖呢。她就是想不开。嗨！\n"); 
    ob->set("marks/ji",1);
    return 1;
}
