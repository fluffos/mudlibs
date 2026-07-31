// yin.c 尹志平
// By Lgg,1998.10
#include <ansi.h>;
inherit NPC;

void create()
{
        set_name("尹志平", ({"yin zhiping", "yin"}));
        set("gender", "男性");
        set("class", "taoist");
        set("nickname", HIM"清和真人"NOR);
        set("age", 24);
        set("long",
                "他是丘处机的得意大弟子尹志平，他粗眉大眼，长的有些英雄气\n"
                "概，在全真教第三代弟子中算得上年轻有为。身材不高，眉宇间\n"
		"似乎有一股忧郁之色。长的倒是长眉俊目，容貌秀雅，面白无须，\n"
		"可惜朱雀和玄武稍有不和。\n");
        set("attitude", "friendly");
        set("shen_type",1);
        set("str", 28);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

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

        set("qi", 5500);
        set("max_qi", 5500);
        set("jing", 800);
        set("max_jing", 800);
        set("neili", 13000);
        set("max_neili", 13000);
        set("jiali", 60);

        set("combat_exp", 580000);
        set("score", 100000);
set_skill("qixing-jian",150);
set_skill("qixing-shou",150);
set_skill("qixing-array",50);
set_skill("hand", 150);
        set_skill("force", 80);
        set_skill("xiantian-qigong", 80);    //先天气功
        set_skill("sword", 80);
        set_skill("quanzhen-jian",90);  //全真剑
        set_skill("dodge", 70);
        set_skill("jinyan-gong", 70);   //金雁功
        set_skill("parry", 80);
        set_skill("unarmed",80);
        set_skill("strike",80);
        set_skill("haotian-zhang", 80);    //昊天掌
        set_skill("literate",60);
        set_skill("taoism",60);

        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike", "haotian-zhang");

        create_family("全真教", 3, "弟子");

        set("inquiry", ([
                "全真教" :  "我全真教是天下道家玄门正宗。\n",
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{
        command("say 好吧，我就收下你这个徒弟了。");
        command("recruit " + ob->query("id"));
}
