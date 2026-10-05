//change.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("阳光", ({"yang guang", "yang", "guang"}));
       set("long","峨嵋山第四代弟子中最杰出的人物之一。\n");
       set("title", HIM"峨嵋派第四代弟子"NOR);
       set("gender", "女性");
       set("age", 17);
       set("class", "xian");
       set("attitude", "friendly");
       set("rank_info/respect", "仙姑");
       set("per", 50);
	set("int", 30);
       set("max_kee", 1000);
       set("max_sen", 1000);
       set("sen", 1000);
       set("kee", 1000);
       set("max_gin", 1000);
       set("max_force", 1000);
       set("max_mana", 1000);
       set("mana", 1000);
       set("force", 1000);
       set("force_factor", 100);
       set("mana_factor", 60);
       set("combat_exp", 800000);
       set("daoxing", 1200000);
       set("eff_dx", 200000);
       set("nkgain", 350);
       set_skill("unarmed", 120);
       set_skill("literate", 120);
       set_skill("dodge", 120);
       set_skill("force", 120);
       set_skill("parry", 120);
       set_skill("sword", 120);
       set_skill("spells", 120);
       set_skill("emeiforce", 120);
       set_skill("huifeng-sword", 120);
       set_skill("zhutian-bu", 120);
       set_skill("mahayana", 120);
       set_skill("jinding-zhang", 120);
       map_skill("sword", "huifeng-sword");
       map_skill("dodge", "zhutian-bu");
       map_skill("force", "emeiforce");
       map_skill("spells", "mahayana");
       map_skill("unarmed", "jinding-zhang");
       create_family("峨嵋派", 4, "弟子");

setup();

           carry_object("/d/obj/cloth/luoyi")->wear();
           carry_object("/d/emei/obj/emeijian")->wield();
        
}

void attempt_apprentice(object ob)

   {
        if ( ob->query_temp("marks/收到") ) {
        if ( (int)ob->query("int") <25){
	 command("shake");
	 command("say 这位" + RANK_D->query_respect(ob) + "你的悟性太少暂时无法领悟我们峨嵋的武功。\n");
        return;
        }

        command("pat "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) + "多加努力，把我们峨嵋发扬光大。\n");
        command("recruit " + ob->query("id") );
        message("system", HIM""+this_player()->name()+HIW"力尽艰难终于拜入了峨嵋山门下。\n"NOR,users());
        ob->set("title", HIM"峨嵋派入门弟子"NOR);
        ob->set("class","xian" );
              ob->delete_temp("marks/收到");


   return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) + "凡入我峨嵋的弟子，还是先去舍身崖找到自己的剑吧。\n");
        return;
}


