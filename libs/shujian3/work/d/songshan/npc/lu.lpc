#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("陆柏", ({ "lu bo", "lu", "bo" }));
        set("nickname", "仙鹤手");
        set("long", "这是一名瘦削的老者，是嵩山派中坐第三把交椅的仙鹤手陆柏。\n");
        set("gender", "男性");
        set("age", 46);
        set("per", 18);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 24);
        set("int", 23);
        set("con", 26);
        set("dex", 26);
         set("unique", 1);
        set("max_qi", 3000);
        set("max_jing", 2000);
        set("eff_jingli", 2000);
        set("jiali", 50);
        set("combat_exp", 1400000);
        set("shen", -14000);

    set_skill("force", 150);
    set_skill("songshan-qigong", 150);
    set_skill("dodge", 150);
    set_skill("zhongyuefeng", 150);
    set_skill("strike", 150);
    set_skill("songyang-zhang", 150);
    set_skill("parry", 150);
    set_skill("sword", 160);
    set_skill("songshan-jian", 160);
    set_skill("literate", 100);
    map_skill("force", "songshan-qigong");
    map_skill("dodge", "zhongyuefeng");
    map_skill("strike", "songyang-zhang");
    map_skill("parry", "songshan-jian");
    map_skill("sword", "songshan-jian");
    prepare_skill("strike", "songyang-zhang");
    create_family("嵩山派", 4, "弟子");
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
                (: perform_action, "sword.feiwu" :),
                (: perform_action, "sword.jianqi" :),
        }));

        setup();
        carry_object(ARMOR_D("changpao1"))->wear();
        carry_object(BINGQI_D("changjian"))->wield();        
        add_money("gold", 1);
}

void attempt_apprentice(object ob)
{
     if(ob->query_skill("songshan-qigong",1) < 90 ||
        ob->query_skill("songshan-jian",1) < 100 ||
        ob->query_skill("songyang-zhang",1) < 90){
        command("say 你的武功还不够娴熟，再回去练练吧。");
        return;
        }
     command("say 好吧，看样子你还算个练武的料。");
     command("recruit " + ob->query("id"));
}
