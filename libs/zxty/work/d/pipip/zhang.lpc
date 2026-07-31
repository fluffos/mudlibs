// zhang.c 张三丰
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("张三丰", ({ "zhang sanfeng", "zhang" }));
    set("nickname", HIG "邋遢真人" NOR);
    set("long", 
        "他就是武当派开山鼻祖、当今武林的泰山北斗张三丰真人。\n"
        "身穿一件污秽的灰色道袍，不修边幅。\n"
        "身材高大，年满百岁，满脸红光，须眉皆白。\n");
    set("gender", "男性");
    set("age", 100);
    set("attitude", "peaceful");
    set("shen_type", 3);
    set("str", 70);
    set("int", 90);
    set("con", 230);
    set("dex", 230);
    
    set("max_qi", 5000);
    set("max_jing", 3000);
    set("max_jingli", 3000);
    set("jingli", 3000);
    set("neili", 30000);
    set("max_neili", 20000);
    set("jiali", 300);
    set("combat_exp", 16637500);
    set("score", 500000);
    set_skill("force", 1850);
    set_skill("taiji-shengong", 1683);
    set_skill("dodge", 1950);
    set_skill("tiyunzong", 1650);
    set_skill("unarmed", 1650);
    set_skill("taiji-quan", 1650);
    set_skill("parry", 1850);
    set_skill("sword", 1800);
    set_skill("taiji-jian", 1800);
    set_skill("blade", 1700);
    set_skill("taiji-dao", 1700);
    set_skill("taoism", 1000);
    set_skill("literate", 1500);
    map_skill("force", "taiji-shengong");
    map_skill("dodge", "tiyunzong");
    map_skill("unarmed", "taiji-quan");
    map_skill("parry", "taiji-jian");
    map_skill("sword", "taiji-jian");
    map_skill("blade", "taiji-dao");
    create_family("武当派", 1, "开山祖师");
    set("class", "taoist");
    set("chat_chance_combat", 60);
    set("chat_msg_combat", ({
        (: perform_action, "sword.lian" :),
        (: perform_action, "sword.chan" :),
        (: perform_action, "sword.sui" :),
        (: exert_function, "recover" :),
    }) );
    setup();
    carry_object("/clone/weapon/changjian")->wield();
    carry_object("/d/wudang/obj/greyrobe")->wear();
}
void attempt_apprentice(object ob)
{
    if ((int)ob->query_skill("taiji-shengong", 1) < 50) {
        command("say 我武当派乃内家武功，最重视内功心法。"); 
        command("say " + RANK_D->query_respect(ob) + 
            "是否还应该在太极神功上多下点功夫？");
        return;
    }
    if ((int)ob->query("shen") < 2000) {
        command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
        command("say 在德行方面，" + RANK_D->query_respect(ob) +
            "是否还做得不够？");
        return;
    }
    if (ob->query_int() < 30) {
        command("say 我武当派武功全从道藏悟出。");
        command("say 要能达到炉火纯青之境，体质什么的倒是无关紧要，悟性却是半点也马虎不得。");
        command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可挖，还是请回吧。");
        return;
    }
    command("chat 哈哈哈哈！！！！");
    command("chat 想不到老道在垂死之年，又觅得一个可塑之才，真是可喜可贺。");
    command("recruit " + ob->query("id"));
}

