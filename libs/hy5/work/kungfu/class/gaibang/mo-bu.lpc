// mo-bu.c
// Modified By Venus. Nov.1997
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("莫不收", ({"mo bushou", "mo", "bushou"}));
        set("title", "丐帮三袋弟子");
        set("gender", "男性");
        set("age", 17);
        set("long",
                "这是位丐帮三袋弟子，看来是个很吃得开的一方霸主。\n");
        set("attitude", "peaceful");
         set("beggarlvl",3);
        set("class", "beggar");
        set("str", 21);
        set("int", 20);
        set("con", 20);
        set("dex", 23);
        set("max_qi", 140);
        set("max_jing", 140);
        set("neili", 180);
        set("max_neili", 180);
        set("jiali", 15);
        set("combat_exp", 18000);
        set_skill("force", 40);
        set_skill("huntian-qigong", 40);
        set_skill("unarmed", 40);
        set_skill("xianglong-zhang", 40);
        set_skill("dodge", 40);
        set_skill("xiaoyaoyou", 40);
        set_skill("parry", 40);
        set_skill("begging", 40);
        set_skill("checking", 40);
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
