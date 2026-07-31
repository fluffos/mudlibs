// ding.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
//inherit F_CLEAN_UP;
// modified by wind

void create()
{
        set_name("丁坚", ({"ding jian","ding",}));
        set("long",
                "他就是隐居江湖数年的一字电剑丁坚，现在在梅庄当管家。\n"
        );
        set("gender", "男性");
        set("nickname", HIC"一字电剑"NOR);
        set("attitude", "friendly");

        set("age", 30);
        set("shen_type", 1);
        set("str", 17);
        set("int", 24);
        set("con", 20);
        set("dex", 22);
        set("max_qi", 13350);
        set("max_jing", 12200);
        set("neili", 11350);
        set("max_neili", 11350);
        set("jiali", 1);
        set("combat_exp", 800000);
        set("score", 100);

        set_skill("force", 80);
        set_skill("dodge", 80);
        set_skill("sword", 120);
        set_skill("parry", 100);
       set_skill("force", 100);
        set_skill("wuzheng-xinfa", 120);
        set_skill("dodge", 100);
        set_skill("piaoyibu", 110);
        set_skill("parry", 120);
        set_skill("sword", 120);
        set_skill("literate", 130);
        
        set_skill("kuihua-xinfa", 100);
        set_skill("pomopima-jian",300);
        map_skill("force", "wuzheng-xinfa");        
        map_skill("dodge", "piaoyibu");
        map_skill("force", "pomopima-jian");
        map_skill("sword", "pomopima-jian");
        map_skill("parry", "pomopima-jian");
        create_family("梅庄", 2, "弟子");

        setup();
        carry_object("/d/city/npc/obj/cloth")->wear();
        carry_object("/d/city/npc/obj/changjian")->wield();
        carry_object("/d/meizhuang/obj/yaoshi");
}


void attempt_apprentice(object ob)
{
        if ((int)ob->query("shen") < 0) {
                command("say 我梅庄虽然不是什么名门正派, 但择徒也极为严格。");
                command("say 在品行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }
        command("say 好吧，在下就收下你了。");
        command("recruit " + ob->query("id"));
}