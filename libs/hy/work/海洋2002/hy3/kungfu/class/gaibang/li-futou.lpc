// li-futou.c
// Modified by Venus. Nov.1997
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("李斧头", ({"li futou", "li", "futou"}));
        set("title", "丐帮六袋弟子");
        set("gender", "男性");
        set("class", "beggar");
        set("age", 20);
   set("beggarlvl",6);
        set("long",
                "这是位丐帮六袋弟子，看来是个深藏不露的高手。\n");
        set("attitude", "peaceful");
        set("str", 27);
        set("int", 25);
        set("con", 24);
        set("dex", 27);
        set("max_qi", 250);
        set("max_jing", 220);
        set("neili",300);
        set("max_neili", 300);
        set("jiali",30);
        set("combat_exp", 60000);

        set_skill("force", 60);
        set_skill("huntian-qigong", 60);
        set_skill("unarmed", 60);
        set_skill("xianglong-zhang", 60);
        set_skill("dodge", 60);
        set_skill("xiaoyaoyou", 60);
        set_skill("parry", 60);
        set_skill("begging", 60);
        set_skill("checking", 60);
        map_skill("force", "huntian-qigong");
        map_skill("unarmed", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        create_family("丐帮", 19, "弟子");
        setup();
}

void attempt_apprentice(object ob)                                              
{
        if( ob->query("gender") != "男性") return;
        command("say 好吧，希望你能好好学习本门武功，将来为丐帮争一口气！。");
        command("recruit " + ob->query("id"));
}
#include "/kungfu/class/gaibang/gaibang.h"
