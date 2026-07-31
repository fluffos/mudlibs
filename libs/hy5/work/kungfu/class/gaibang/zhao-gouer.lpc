// zhao-gouer.c
// Modified by Venus Nov.1997
inherit NPC;
inherit F_MASTER;
void create()                                                                   
{
        set_name("赵狗儿", ({"zhao gouer", "zhao", "gouer"}));
        set("title", "丐帮一袋弟子");
        set("gender", "男性");
        set("age", 15);
        set("long",
                "这是位地痞似的丐帮一袋弟子，看来是个小地痞。\n");
        set("attitude", "peaceful");
        set("class", "beggar");
        set("str", 18);
        set("beggarlvl",1);
        set("int", 20);
        set("con", 20);
        set("dex", 23);
        set("max_qi", 120);
        set("max_jing", 120);
        set("neili", 150);
        set("max_neili", 150);
        set("jiali", 5);
        set("combat_exp", 2500);
        set_skill("force", 10);
        set_skill("huntian-qigong", 10);
        set_skill("unarmed", 10);
        set_skill("xianglong-zhang", 10);
        set_skill("dodge", 10);
        set_skill("xiaoyaoyou", 10);
        set_skill("parry", 10);
        set_skill("begging", 10);
        set_skill("checking", 10);
        map_skill("force", "huntian-qigong");
        map_skill("unarmed", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        create_family("丐帮", 20, "弟子");
        setup();
}
void attempt_apprentice(object ob)
{
        if( ob->query("gender") != "男性") return;
        command("say 好吧，希望你能好好学习本门武功，将来为丐帮争一口气！。");
        command("recruit " + ob->query("id"));
}
#include "/kungfu/class/gaibang/gaibang.h"
