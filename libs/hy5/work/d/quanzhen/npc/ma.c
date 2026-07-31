// ma.c 马钰
// By Lgg,1998.10

#include <ansi.h>
inherit NPC;

string ask_me();

void create()
{
        set_name("马钰", ({"ma yu", "ma"}));
        set("gender", "男性");
        set("age", 42);
        set("class", "taoist");
        set("nickname",MAG"丹阳子"NOR);
        set("long",
                "他就是王重阳的大弟子，全真七子之首，丹阳子马钰马真人。\n"
                "他慈眉善目，和蔼可亲，正笑着看着你。\n");
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 28);
        set("int", 32);
        set("con", 31);
        set("dex", 30);

        set("title","全真七子之首");

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
set_skill("qixing-jian",250);
set_skill("qixing-shou",250);
set_skill("qixing-array",250);
set_skill("hand", 300);
        set_skill("force", 150);
        set_skill("xiantian-qigong", 150);    //先天气功
        set_skill("sword", 140);
        set_skill("quanzhen-jian",140);  //全真剑
        set_skill("dodge", 120);
        set_skill("jinyan-gong", 140);   //金雁功
        set_skill("parry", 150);
        set_skill("unarmed",140);
        set_skill("array",100);
        set_skill("array",200);
        set_skill("qixing-array",200);
        set_skill("haotian-zhang", 140);    //昊天掌
        set_skill("literate",100);
        set_skill("strike",120);
        set_skill("taoism",110);
	map_skill("array","qixing-array");
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
                "金雁功" : (: ask_me :),
                "金雁图谱" : (: ask_me :),
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
        command("pat " + ob->query("id"));
        command("say 好吧，我就收下你这个徒弟了。");
        command("recruit " + ob->query("id"));
}

string ask_me()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "全真教")
                return RANK_D->query_respect(this_player()) +
                "与本教毫无瓜葛，我教的武功典籍可不能交给你。";
        if (query("book_count") < 1)
                return "你来晚了，金雁图谱已经被人取走了。";
        add("book_count", -1);
        ob = new("/clone/book/jinyantu");
        ob->move(this_player());
        return "好吧，这本「金雁图谱」你拿回去好好研读。";

}
