
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
       set_name("白眉大师", ({"bai mei", "bai", "mei","master"}));
       set("long", "峨嵋派开山祖师, 执掌峨嵋以有两千多年。\n");
       set("title", HIW"峨嵋派天地师尊"NOR);
       set("gender", "男性");
       set("age", 100);
       set("class","xian");
       set("attitude", "friendly");
       set("rank_info/respect", "老头");
       set("cor", 30);
       set("per", 30);
       set("looking", "一脸的忧愁。");
       set("max_kee", 5000);
       set("max_sen", 5000);
       set("sen", 5000);
       set("kee", 5000);
       set("max_gin", 800);
       set("max_force", 3000);
       set("max_mana", 3000);
       set("mana", 3000);
       set("force", 3000);
       set("force_factor", 125);
       set("mana_factor", 160);
       set("combat_exp", 3500000);
       set("daoxing", 4500000);
       set_skill("literate", 200);
       set_skill("unarmed", 220);
       set_skill("dodge", 220);
       set_skill("force", 220);
       set_skill("parry", 220);
       set_skill("sword", 220);
       set_skill("spells", 220);
       set_skill("emeiforce", 220);
       set_skill("tianlei-sword", 220);
       set_skill("zhutian-bu", 220);
       set_skill("mahayana", 220);
       set_skill("jinding-zhang", 220);
       map_skill("sword", "tianlei-sword");
       map_skill("dodge", "zhutian-bu");
       map_skill("force", "emeiforce");
       map_skill("spells", "mahayana");
       map_skill("unarmed", "jinding-zhang");

	set("inquiry", ([
		"name": "我是白眉！\n",
		"here": "峨嵋山！\n",
	]) );


   create_family("峨嵋派", 1, "白");
setup();

   carry_object("/d/emei/obj/haotianjing.c");
   carry_object("/d/emei/obj/shoes")->wear();
}
void init()
{
add_action("do_kneel","kneel");
}

void attempt_apprentice(object ob)

   {

   if ( (string)ob->query("family/family_name")=="峨嵋派") {
   if (((int)ob->query("combat_exp") < 1500000 )) 
        {
   command("say " + RANK_D->query_respect(ob) + "的武学修为不够高深，有些绝学秘法恐怕难以领悟。\n");
   return;
        }
   if( (int)ob->query_skill("emei-force") > 199 ) 
        {
   command ("say " + RANK_D->query_respect(ob) + "你的峨嵋心法修为不够，为师不能收你为徒。");
   return;
        }
   if( (int)ob->query_skill("mahayana") > 199 ) 
        {
   command ("say " + RANK_D->query_respect(ob) + "你的大乘涅磐功修为不够，为师不能收你为徒。");
   return;
        }
   if( (int)ob->query_skill("tianji-sword") > 1 ) 
        {
   command ("say " + RANK_D->query_respect(ob) + "请你先放弃你所学到的天玑剑法，为师才能收你为徒。");
   return;
        }
   if( (int)ob->query_skill("leiyan-sword") > 1 ) 
        {
   command ("say " + RANK_D->query_respect(ob) + "请你先放弃你所学到的雷炎剑法，为师才能收你为徒。");
   return;
        }

        command("pat "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) + "多加努力，把我们峨嵋发扬光大。\n");
        command("recruit " + ob->query("id") );
        ob->set("title", HIW"峨嵋派白眉真传弟子"NOR);

   return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) + "还是先去学些基础功夫吧。\n");
        return;
}

