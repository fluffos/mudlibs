//create bye cuer
//modified by advent
inherit NPC;
#include <ansi.h>
string ask_jian();
void create()
{
        set_name("方碧琳", ({
                "fang bilin",
                "fang",
                "bilin",
        }));
        set("long",
                "她是一位年轻漂亮的姑娘。\n"
        );
        set("gender", "女性");
        set("attitude", "friendly");
        set("age", 26);
        set("shen_type", 1);
        set("str", 21);
        set("int", 25);
        set("con", 20);
        set("dex", 25);
        set("no_get", 1);
        set("max_qi", 1000);
        set("max_jing", 500);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 70);
        set("combat_exp", 150000);
        set("score", 100);
        set("inquiry",(["倚天剑":
        (: ask_jian :),
        ]));
        set("jian_count",random(6)-4);
        set_skill("force", 100);
        set_skill("linji-zhuang", 100);
        set_skill("dodge", 100);
        set_skill("zhutian", 100);
        set_skill("fuliu-jian", 100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("mahayana", 100);
        set_skill("literate", 100);
        map_skill("force", "linji-zhuang");
        map_skill("dodge", "zhutian");
        map_skill("sword", "fuliu-jian");
        map_skill("parry", "fuliu-jian");
        prepare_skill("sword", "fuliu-jian");
        
        create_family("峨嵋派", 4, "弟子");
        setup();
        carry_object(__DIR__"obj/changjian")->wield();
        carry_object(__DIR__"obj/cloth")->wear();
}
string ask_jian()
{
        object ob;
        if ((int)this_player()->query("combat_exp") < 5000000)
        return "你的武功如此之差。师父怎么放心将倚天剑交你保管？！";
	if (this_player()->query("family/family_name") != "峨嵋派")
		return "倚天剑是我峨嵋派镇山之宝，不能给你！\n";
        if ((int)this_player()->query("score") < 2500)
        return "你对峨嵋派不够忠心，师父怎么放心将倚天剑交你保管？";        
        if (query("jian_count") < 1)
        return "你来晚了，倚天剑已经送与有缘人。";
        add("jian_count", -1);
        ob = new(__DIR__"obj/yitian-jian");
        ob->move(this_player());
        CHANNEL_D->do_channel(this_object(), "rumor", "听说倚天剑落入了"+this_player()->name()+"之手！");
        return RANK_D->query_respect(this_player()) +
                "天资聪颖，对峨嵋忠心耿耿，且已得师父真传，想必能参出倚天剑中秘密，就交与你保管吧!";
}
        
void attempt_apprentice(object ob)
{
  command("say 我不收徒，我要伺候我师傅一辈子。\n");
}    

