// qiu.c 丘处机
// By Lgg,1998.10

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("丘处机", ({"qiu chuji", "qiu"}));
        set("gender", "男性");
        set("age", 36);
        set("class", "taoist");
        set("nickname",HIM"长春子"NOR);
        set("long",
                "他就是江湖上人称‘长春子’的丘处机丘真人，他方面大耳，\n"
                "满面红光，剑目圆睁，双眉如刀，相貌威严，平生疾恶如仇。\n");
        set("attitude", "heroism");
        set("shen_type",1);
        set("str", 32);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("title","全真七子之四");

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

set_skill("qixing-array",200);
        set_skill("force", 150);
        set_skill("xiantian-qigong", 150);    //先天气功
        set_skill("sword", 150);
        set_skill("quanzhen-jian",150);  //全真剑
        set_skill("dodge", 120);
        set_skill("jinyan-gong", 150);   //金雁功
        set_skill("parry", 150);
        set_skill("haotian-zhang", 150);    //昊天掌
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

void init()
{
        ::init();
        remove_call_out("greeting");
        call_out("greeting", 1, this_player());
}


void greeting(object ob)
{
        mapping fam;
        int i ;
        object me;

        me = this_object();
if (environment(ob)->query("short")=="金刚伏魔圈"){
        if (interactive(ob) && !environment(ob)->query("no_fight"))
        {
             if (!(fam = ob->query("family")) || fam["family_name"] != "全真教")
 {
                if (ob->query("shen")>-5000) {
                        command("say 这里是本教重地，你走动小心些。");
                }
                else {
                        command("say 你这魔头，竟敢闯入我全真重地，我一定要杀了你！");
                        me->set_leader(ob);
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob);
                }
             }
             else {
                command("smile "+ob->query("id"));
             }
        }
}
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

