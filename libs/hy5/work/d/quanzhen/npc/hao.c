// hao.c 郝大通
// By Lgg,1998.10

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("郝大通", ({"hao datong", "hao"}));
        set("gender", "男性");
        set("age", 34);
        set("class", "taoist");
        set("nickname",HIG"广宁子"NOR);
        set("long",
                "他就是全真七子中的郝大通郝真人。他身材微胖，象个富翁模\n"
                "样，身上穿的道袍双袖皆无。\n" );
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 30);
        set("int", 29);
        set("con", 29);
        set("dex", 29);

        set("title","全真七子之六");

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

        set_skill("force", 130);
        set_skill("xiantian-qigong", 130);    //先天气功
        set_skill("sword", 130);
        set_skill("quanzhen-jian",130);  //全真剑
        set_skill("dodge", 110);
        set_skill("jinyan-gong", 120);   //金雁功
        set_skill("parry", 140);
        set_skill("unarmed",150);
        set_skill("haotian-zhang", 150);    //昊天掌
        set_skill("literate",100);
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

