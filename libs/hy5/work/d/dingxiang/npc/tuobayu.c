
inherit F_MASTER;
inherit NPC;

#include <ansi.h>

int do_action1();

void create()
{
   set_name("ÍØ°ÏÓñ",({ "tuoba yu","tuoba","yu" }) );
   set("gender", "ÄÐÐÔ" );		
   set("age",24);
   set("long", "Ëû¾ÍÊÇ±ÏÐþµÄÍ½µÜ¡£\n");       
   set("combat_exp",600000);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("force",150);
   set_skill("whip",150);
   set_skill("literate",150);
  

  
   set("max_jing",2000);
   set("max_qi",2000);
   set("max_sen",2000);
   set("neili",2000);
   set("max_neili",2000);
   create_family("Í»ØÊ",5,"ÎäÊ¿");

   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/whip")->wield();
  
}

