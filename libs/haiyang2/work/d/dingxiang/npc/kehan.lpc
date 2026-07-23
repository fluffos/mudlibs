

inherit NPC;

#include <ansi.h>


int do_action1();

void create()
{
   set_name("颉利大汗",({ "da han","da","han" }) );
   set("gender", "男性" );	
   set("age", 50);
   set("combat_exp",6000000);
   set("str", 25);
   set("per", 22);
   
   set_skill("dodge",300);
   set_skill("parry",300);
   set_skill("force",300);
   set_skill("whip",300);
   set_skill("literate",300);
  

   set("max_jing",30000);
   set("max_qi",30000);
   set("max_sen",30000);
   set("neili",30000);
   set("max_neili",30000);
   set("inquiry",([
    "飞挝鞭法":(:do_action1:),
    ]));
   create_family("突厥",2,"大汗");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/whip")->wield();
  
}

