// xuan.c 静玄师太
//Modified by That Oct.1997
#include <command.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_for_join();
void create()
{

        set_name("静玄师太", ({ "jingxuan shitai","jingxuan","shitai"}));
        set("long",
          "她是峨嵋派大师姐，跟随灭绝师太二十余载，峨嵋派的基本功夫已尽得所传。\n");
        set("gender", "女性");
        set("age", 42);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("shen", 10000);
        set("class", "bonze");
        set("inquiry",([
                "剃度"  : (: ask_for_join :),
                "出家"  : (: ask_for_join :),
                "还俗"  : "峨嵋弟子，不能还俗。你找掌门师太吧。",
        ]));

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 20);

            set("max_qi", 6000);
        set("max_jing", 6500);
        set("neili", 6500);
        set("max_neili", 6500);
        set("jingli", 1500);
        set("max_jingli", 1500);

        set("combat_exp", 350000);
        set("score", 1000);
        set_skill("persuading", 180);
        set_skill("throwing", 160);
        set_skill("force", 160);
        set_skill("dodge", 170);
        set_skill("finger", 175);
        set_skill("parry", 170);
        set_skill("strike", 160);
        set_skill("sword", 180);
        set_skill("literate", 170);
        set_skill("mahayana", 160);
        set_skill("jinding-zhang", 160);
        set_skill("tiangang-zhi", 165);
        set_skill("huifeng-jian", 160);
        set_skill("zhutian-bu", 160);
        set_skill("linji-zhuang", 160);
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("parry","huifeng-jian");
        prepare_skill("strike", "jinding-zhang");
        prepare_skill("finger", "tiangang-zhi");	
set_temp("huifeng/jue",1);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
                (: perform_action, "sword.sanqing" :),
                	(: perform_action, "sword.jue" :),
                	(: perform_action, "sword.liaoyuan" :),                		
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "strike.puzhao" :),
                (: perform_action, "strike.bashi" :),
                (: perform_action, "finger.lingkong" :),
                (: exert_function, "daxiao" :),
                (: exert_function, "fengyun" :),
                (: exert_function, "longhe" :),
                (: exert_function, "tiandi" :),                                
                (: exert_function, "juemie" :), 
        }) );

        create_family("峨嵋派", 4, "弟子");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/city/obj/cloth.c")->wear();
}
void init()
{
        add_action("do_kneel", "kneel");
}

void attempt_apprentice(object ob)
{
   if( (string)ob->query("class")!="bonze" )
   {
      command ("say 阿弥陀佛！贫尼不收弟子。\n");
      command ("say 你若想继续学峨嵋派的功夫，还是去找我俗家师妹吧。\n");
      return;
   }
   if( (string)ob->query("gender") != "女性" )
   {
      command ("say 阿弥陀佛！贫尼不收男弟子。施主若想学艺可去找我俗家师妹。");
      return;
   }
   if ((int)ob->query("shen") < 100)
   {
      command("say " + RANK_D->query_respect(ob) + "你行侠仗义之事还做的不够。");
      return;
   }
   if ((int)ob->query_skill("mahayana",1) <50)
   {
      command("say 你大乘佛法的修为还要提高些。");
      return;
   }
   command("say 阿弥陀佛，善哉！善哉！好吧，我就收下你了。");
   command("say 希望你能以慈悲之心，以智慧之力，努力行善，济度众生。");
   command("recruit " + ob->query("id"));
}
#include "tobebonze.h"
