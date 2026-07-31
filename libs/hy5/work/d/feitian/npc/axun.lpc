// axun.c 阿熏
// 青云(diabio)2003.3.21
#include <ansi.h>;
inherit NPC;
string ask_lianxi();
void create()
{
        set_name("神古熏", ({"shengu xun", "shengu"}));
        set("gender", "女性");
//        set("nickname", HIC"神古活心流"NOR);
             	set("title", HIC"神古活心流代师傅"NOR);
        set("age", 20);
                 set("rank","十刃");
        set("long",
            "绯村剑心的爱人就是她了，为了剑心她可以用生命来替代\n"
            "曾经是神古活心流的代师傅，提倡的是不伤人的剑法。\n"
            "看上去她显的非常美丽，但生气起来可是非常恐怖的。\n");
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 28);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
              set("per", 28);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "unarmed.qin" :),
                (: perform_action, "unarmed.niu" :),
                (: perform_action, "unarmed.yaozhan" :),
                (: perform_action, "blade.chaodao" :),
        }));

        set("qi", 6500);
        set("max_qi", 6500);
        set("jing", 6800);
        set("max_jing", 6800);
        set("neili", 8000);
        set("max_neili", 8000);
        set("jiali", 60);

        set("combat_exp", 888888);
        set("score", 100000);

                set_skill("cuff",150);
        set_skill("force", 150);
        set_skill("shayi-xinfa", 190); 
        set_skill("blade", 180);
        set_skill("huoxinliu-jianfa",190); 
        set_skill("dodge", 150);
        set_skill("wuxing-dun", 190);  
        set_skill("parry", 250);
        set_skill("unarmed",150);
        set_skill("shayi",190);
        set_skill("aikido", 180);    
        set_skill("literate",180);

        map_skill("force", "shayi-xinfa");
        map_skill("blade", "huoxinliu-jianfa");
        map_skill("dodge", "wuxing-dun");
        map_skill("parry", "feitian-yujianliu");
        map_skill("unarmed", "aikido");
        prepare_skill("unarmed", "aikido");
       set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        create_family("飞天御剑流", 7, "代师傅");

        set("inquiry", ([
                "剑心" :  "不知道他现在可好，我很牵挂他。\n",
                            "活心流剑法" :  "神古活心流最高剑决为抄刀，但使用过于危险。\n",
                "抄刀" :  "使用抄刀太过与凶险，基本功的练习很重要。\n",
                "练习" :  (: ask_lianxi :),
        ]) );

        setup();

      carry_object(__DIR__"obj/hefu")->wear();
      carry_object(__DIR__"obj/shoes")->wear();
          carry_object(__DIR__"obj/zhujian")->wield();

}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("shayi-xinfa") > 100) {
                command("say " + RANK_D->query_respect(ob) +
                        "杀意心法在于杀意，你的杀意如此之低只怕会被剑所控制？");
                return;
}
        command("say 好吧，我就收下你这个徒弟了，希望你能知道剑是用来救人。");
        command("recruit " + ob->query("id"));
	ob->set("title",HIR"【神古活心流】"HIW"代师傅"NOR);
            ob->set("class", "yujianliu");
}	

string ask_lianxi()
{
        object me=this_player();
        me->set_temp("tmark/练习",1);
        return("叹了口气道：好吧你你修炼室练习去吧，要主意的是抄刀重要的是基本功。\n");
}

