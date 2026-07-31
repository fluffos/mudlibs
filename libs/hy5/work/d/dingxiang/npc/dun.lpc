
inherit F_MASTER;
inherit NPC;

#include <ansi.h>

int do_action1();

void create()
{
   set_name("墩欲谷",({ "dun yugu","dun" }) );
   set("gender", "男性" );
   set("age", 42);
   
   set("long", "他就是毕玄的弟弟，深得突厥大汗的信任．\n");
       
   set("combat_exp",1000000);
 
   set_skill("dodge",200);
   set_skill("parry",200);
   set_skill("force",200);
   set_skill("whip",200);
   set_skill("literate",200);
  

   set("max_jing",3000);
   set("max_qi",3000);
   set("max_sen",3000);
   set("neili",3000);
   set("max_neili",3000);
   create_family("突厥",3,"武士");

   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/whip")->wield();
  
}
