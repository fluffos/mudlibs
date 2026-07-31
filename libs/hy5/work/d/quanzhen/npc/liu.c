// liu.c 刘处玄
// By Lgg,1998.10

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("刘处玄", ({"liu chuxuan", "liu"}));
        set("gender", "男性");
        set("age", 38);
        set("class", "taoist");
        set("nickname",WHT"长生子"NOR);
        set("long",
                "他就是全真三徒刘处玄刘真人，他身材瘦小，但顾盼间自有一\n"
                "种威严气概。\n");
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 30);
        set("int", 30);
        set("con", 28);
        set("dex", 30);

        set("title","全真七子之三");

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.ding" :),
        }));

        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 1600);
        set("max_jing", 1600);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 100);

        set("combat_exp", 800000);
        set("score", 300000);

set_skill("qixing-array",100);
        set_skill("force", 140);
        set_skill("xiantian-qigong", 140);    //先天气功
        set_skill("sword", 140);
        set_skill("quanzhen-jian",140);  //全真剑
        set_skill("dodge", 120);
        set_skill("jinyan-gong", 140);   //金雁功
        set_skill("unarmed",140);
        set_skill("parry", 140);
        set_skill("strike",140);
        set_skill("haotian-zhang", 140);    //昊天掌
        set_skill("literate",80);
        set_skill("strike",120);
        set_skill("taoism",100);

        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike", "haotian-zhang");

        create_family("全真教", 2, "弟子");

        set("book_count",1);
        set("inquiry", ([
                "全真教" :  "我全真教是天下道家玄门正宗。\n",
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{
        if ((int)ob->query_skill("xiantian-qigong",1) < 50 ) {
                command("say 你的本门内功心法火候不足,难以领略更高深的武功。");
                return;
        }
        if ((int)ob->query("shen")<5000) {
                command("say 行侠仗义是我辈学武人的基本品质，你若能多做些狭义之
事，我一定收你为徒。\n");
                return;
        }
        command("say 好吧，我就收下你这个徒弟了。");
        command("recruit " + ob->query("id"));
}

