
inherit F_MASTER;
inherit NPC;

#include <ansi.h>

int do_action1();

void create()
{
   set_name("Ä½ÌúÐÛ",({ "mu tiexiong","mu","tiexiong" }) );
   set("gender", "ÄÐÐÔ" );		
   set("age",30);
   set("nickname","º·Ê¨");
   set("long", "Ëû¾ÍÊÇÍ»ØÊÈË³Æ¡¸º·Ê¨¡¹µÄÄ½ÌúÐÛ¡£\n");       
   set("combat_exp",100000);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("force",100);
   set_skill("finger",100);
   set_skill("literate",100);

  
   set("max_jing",1000);
   set("max_qi",1000);
   set("max_sen",1000);
   set("neili",1000);
   set("max_neili",1000);

   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   
  
}
