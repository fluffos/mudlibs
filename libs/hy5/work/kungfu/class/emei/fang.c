// fang.c 方碧琳

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("方碧琳", ({ "fang bilin","fang","bilin"}));
        set("long",
                "她是峨嵋派的第四代俗家弟子。\n");
        set("gender", "女性");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("shen", 10000);
        set("class", "fighter");

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

        set("combat_exp", 150000);
        set("score", 1000);
        set_skill("persuading", 40);
        set_skill("throwing", 30);
        set_skill("force", 60);
        set_skill("dodge", 80);
        set_skill("finger", 50);
        set_skill("parry", 70);
        set_skill("strike", 80);
        set_skill("blade", 60);
        set_skill("jinding-zhang", 80);
        set_skill("tiangang-zhi", 50);
        set_skill("yanxing-dao", 60);
        set_skill("zhutian-bu", 80);
        set_skill("linji-zhuang", 60);

        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("blade","yanxing-dao");
        map_skill("parry","yanxing-dao");

        create_family("峨嵋派", 4, "弟子");

        setup();
        carry_object("/d/city/obj/gangdao")->wield();
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
