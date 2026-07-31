// miyan.c 弥彦
// 青云(diabio)2003.3.21
#include <ansi.h>;
inherit NPC;

void create()
{
        set_name("弥彦", ({"mi yan", "yan"}));
        set("gender", "男性");
        set("nickname", HIM"空手入白刃"NOR);
        set("age", 16);
        set("long",
            "他曾经和绯村剑心共同对抗过十刃的入侵,还成功击退其一\n"
            "十刃之役结束后,更把飞天御剑流和神古活心流融会贯通。\n"
            "成为天下数一数二的剑客.在他年轻的脸上流露出一股不屈的神情。\n");
        set("attitude", "friendly");
        set("shen_type",1);
        set("str", 28);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "unarmed.qin" :),
                (: perform_action, "unarmed.niu" :),
                (: perform_action, "unarmed.yaozhan" :),
                (: perform_action, "blade.chaodao" :),
        }));

        set("qi", 8500);
        set("max_qi", 8500);
        set("jing", 1800);
        set("max_jing", 1800);
        set("neili", 15000);
        set("max_neili", 15000);
        set("jiali", 20);

        set("combat_exp", 1480000);
        set("score", 100000);

        set_skill("force", 100);
        set_skill("shayi-xinfa", 160); 
        set_skill("blade", 100);
        set_skill("huoxinliu-jianfa",160); 
        set_skill("dodge", 100);
        set_skill("wuxing-dun", 160);  
        set_skill("parry", 100);
        set_skill("unarmed",100);
        set_skill("shayi",100);
        set_skill("aikido", 100);    
        set_skill("literate",100);
//        set_skill("bearart",100);

        map_skill("force", "shayi-xinfa");
        map_skill("blade", "huoxinliu-jianfa");
        map_skill("dodge", "wuxing-dun");
        map_skill("parry", "huoxinliu-jianfa");
        map_skill("unarmed", "aikido");
        prepare_skill("unarmed", "xuanhualiu-quanfa");

        create_family("飞天御剑流", 8, "弟子");

        set("inquiry", ([
                "飞天御剑流" :  "飞天御剑流是拯救乱世的剑法。\n",
      "小燕":     "她在牛肉馆做事，你找她有事吗。",
      "绯村剑心":     "最近听说他跑到山里找他师傅学习剩下的剑招去了。",
        ]) );

        setup();

      carry_object(__DIR__"obj/hefu")->wear();
      carry_object(__DIR__"obj/shoes")->wear();
          carry_object(__DIR__"obj/zhujian")->wield();

}

void attempt_apprentice(object ob)
{
        command("say 好吧，我就收下你,大家一起学习。");
        command("recruit " + ob->query("id"));
	ob->set("title",HIR"【神古活心流】"HIW"门下生"NOR);
       ob->set("class", "yujianliu");
}


