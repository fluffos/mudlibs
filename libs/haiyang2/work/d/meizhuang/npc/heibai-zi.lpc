// heibai.c
inherit NPC;
inherit F_MASTER;


void create()
{
        set_name("黑白子", ({ "heibai zi", "zi" }));
        set("title", "梅庄二庄主");
        set("long",
                "他就是梅庄四位庄主排行第二的秃笔翁。\n"
                "身穿一件干干净净的黑色长袍。\n"
                "他已年愈五旬，身材高大，双眼神光内敛, 一望便知是一位内家的高手。\n");
        set("gender", "男性");
        set("age", 52);
        set("class", "scholar");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 12000);
        set("max_jing", 12000);
        set("neili", 12000);
        set("max_neili", 12000);
        set("jiali", 80);
        set("combat_exp", 6000000);
        set("shen", 15000);
        set("score", 60000);

set_skill("goplaying", 300);
        set_skill("force", 120);
        set_skill("wuzheng-xinfa", 120);
        set_skill("dodge", 100);
        set_skill("piaoyibu", 110);
        set_skill("parry", 120);
        set_skill("finger", 200);
        set_skill("staff", 200);
        set_skill("jiangjun-zhang", 300);
        set_skill("xuantian-zhi", 140);
        set_skill("literate", 130);
set_skill("kuihua-xinfa", 200);
        map_skill("force", "wuzheng-xinfa");
        map_skill("dodge", "piaoyibu");
        map_skill("parry", "xuantian-zhi");
        map_skill("staff", "jiangjun-zhang");
        map_skill("finger", "xuantian-zhi");
        prepare_skill("finger", "xuantian-zhi");
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
        create_family("梅庄", 1, "庄主");

        setup();
        carry_object("/clone/weapon/gangzhang")->wield();
        carry_object(__DIR__"obj/heiyi")->wear();

}

void attempt_apprentice(object ob)
{
        if ((int)ob->query_skill("wuzheng-xinfa",1) < 90) {
                command("say 我是不轻易收徒的。");
                command("say 在我梅庄的内功上，" + RANK_D->query_respect(ob) +
                        "是否还应该多下点功夫？");
                return;
        }
        command("say 好吧，在下就收下你了。");
        command("recruit " + ob->query("id"));
}

